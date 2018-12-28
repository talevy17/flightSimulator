#include <fstream>
#include "FlightController.h"
#define NOT_FOUND -1

typedef vector<string> :: iterator vecitr;

/**
 * constructor - gets file or command line, check if its file
 */

FlightController::FlightController(bool *stop) {
    this->shouldStop = stop;
    this->flightDataVariables.flightDataInit();
    initializeCommandMap();
}

/**
 * initialize the commands map, create new commands
 */

void FlightController::initializeCommandMap() {
    mutex m;
    this -> client = new Client();
    this -> server = new Server(m, this->flightDataVariables);
    this->commandMap.insert(pair<string, Command *>("openDataServer",
            new OpenDataServer(*this->server,this->flightDataVariables)));
    this->commandMap.insert(pair<string,Command*>("connect",
            new ConnectCommand(&this->flightDataVariables,this->client)));
    this->commandMap.insert(pair<string, Command *>("if",
            new IfCommand(&this->flightDataVariables, &this->commandMap)));
    this->commandMap.insert(pair<string, Command *>("while",
            new WhileCommand(&this->flightDataVariables, &this->commandMap)));
    this->commandMap.insert(pair<string,Command*>("print",
            new PrintCommand(&this->flightDataVariables)));
    this->commandMap.insert(pair<string, Command *>("var",
            new VarCommand(&this->flightDataVariables,this->client,m)));
    this->commandMap.insert(pair<string,Command*>("sleep",
            new SleepCommand(&this->flightDataVariables)));
    this->commandMap.insert(pair<string,Command*>("exit",
            new SafeExit(this->shouldStop)));

}


/**
 * the function gets the file ifstream and read untill the end of condition
 * @param file - the input file.
 * @param commandLine - vector of strings that hold commands
 * @param lexer
 */

void readCondition(ifstream &file, vector<string> &commandLine, Lexer lexer) {
    int numOfConditions = 1;
    string line;
    while (numOfConditions>0) {
        getline(file, line);
        if (line==""){
            getline(file, line);
            continue;
        } else if (line.find('{')!=NOT_FOUND){
            numOfConditions ++;
        } else if (line.find('}') != NOT_FOUND) { numOfConditions --; }
        lexer.splitLine(line, commandLine);
    }
}

/**
 * the function gets input string  - line of command or file name.
 * if its a file - read each line and call lexer and parser,
 * if its a line - call lexer and parser.
 * @param input - string : file name or line of command
 * @param isFile - true - if the input is file, false - else
 */

void FlightController::controller(string input, bool isFile) {
    vector<string> commandLine;
    Lexer lexer;
    if (isFile) {
        ifstream file(input);
        if (!file.is_open()) { throw "error file not found"; }
        string line;
        while (getline(file, line)) {
            if (line == ""){ continue;}
            // if there is an condition - read till the end of the condition
            if (line.find('{')!= NOT_FOUND) {
                lexer.splitLine(line, commandLine);
                readCondition(file, commandLine, lexer);
            } else {
                lexer.splitLine(line, commandLine);
            }
            parser(commandLine);
            commandLine.clear();
        }
    } else {
        lexer.splitLine(input, commandLine);
        parser(commandLine);
    }
}

/**
 * the function gets vector of commands, match each title to the actual command
 * and execute.
 * @param commandLine - reference to queue of strings that holds the commands
 */

void FlightController::parser(vector<string> &commandLine) {
    vecitr commandIt;
    for (commandIt = commandLine.begin(); commandIt < commandLine.end(); ++commandIt) {
        //check if the current index in the commandLine is command
        Command *command;
        try {
            // we want any command to be expression -
            command = commandMap.at(*commandIt);
            CommandExpression c(command, commandIt);
            c.calculate();
        } catch (const exception& er) {
            try {
                flightDataVariables.getVar(*commandIt);
                CommandExpression v (commandMap.at("var"),commandIt);
                v.calculate();
            }
            catch (const char *exception) {
                throw "error, undefined command"; }
        }
    }
}