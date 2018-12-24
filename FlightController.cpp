#include <fstream>
#include "FlightController.h"
#include "Lexer.h"
#include "OpenDataServer.h"

/**
 * constructor - gets file or command line, check if its file
 */

FlightController::FlightController() {
    this->flightDataVariables.flightDataInit();
    initializeCommandMap();
}

/**
 * initialize the commands map, create new commands
 */

void FlightController::initializeCommandMap() {
    //this->commandMap.insert(pair<string, Command *>("openDataServer", new OpenDataServer (this->flightDataVariables)));
    //this->commandMap.insert(pair<string,Command*>("connect",new ConnectCommand));
    this->commandMap.insert(pair<string, Command *>("if",
                                                    new IfCommand(&this->flightDataVariables, &this->commandMap)));
    this->commandMap.insert(pair<string, Command *>("while",
                                                    new WhileCommand(&this->flightDataVariables, &this->commandMap)));
    //this->commandMap.insert(pair<string,Command*>("print",new PrintCommand));
    this->commandMap.insert(pair<string, Command *>("var",
                                                    new VarCommand(&this->flightDataVariables)));
    //this->commandMap.insert(pair<string,Command*>("sleep",new SleepCommand));
}


/**
 * the function gets the file ifstream and read untill the end of condition
 * @param file - the input file.
 * @param commandLine - vector of strings that hold commands
 * @param lexer
 */

void readCondition(ifstream *file, vector<string> &commandLine, Lexer lexer) {
    string line;
    bool endOfCondition = false;
    while (!endOfCondition) {
        if (line.find('}')) { endOfCondition = true; }
        lexer.splitLine(line, commandLine);
        //check
        getline(*file, line);
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
            // if there is an condition - read till the end of the condition
            if (line.find('{')) {
                lexer.splitLine(line, commandLine);
                readCondition(&file, commandLine, lexer);
            } else {
                lexer.splitLine(line, commandLine);
            }
            parser(commandLine);
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
    vector<string>::iterator commandIt;
    commandIt = commandLine.begin();
    while (commandIt != commandLine.end()) {
        //check if the current index in the commandLine is command
        Command *command = commandMap.at(*commandIt);
        //if its not command- check if its variable.
        if (command == nullptr) {
            //check if the current index in the commandLine is variable
            try { flightDataVariables.getVar(*commandIt); }
            catch (const char *exception) { throw "error, undefined command"; }
        } else {
            command->execute(commandIt);
        }
        ++commandIt;
    }
}