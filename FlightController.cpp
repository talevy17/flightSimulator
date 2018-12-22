#include <fstream>
#include "FlightController.h"
#include "Lexer.h"
#include "OpenDataServer.h"

#define ASSIGN_COMMAND "="

/**
 * constructor - gets file or command line, check if its file
 */
FlightController::FlightController(string str, bool isFile) {
    this->flightDataVariables.flightDataInit();
    this->input = str;
    this->isFile = isFile;
    //check if the file exist
    if (isFile) {
        ifstream file(str);
        if (!file.is_open()) { throw "error file not found"; }
    }
    initialize();
}

void FlightController::initialize() {
    this->commandMap.insert(pair<string, Command *>("openDataServer", new OpenDataServer(this->flightDataVariables)));
    //this->commandMap.insert(pair<string,Command*>("connect",new ConnectCommand));
    this->commandMap.insert(pair<string, Command *>("if",
                                                    new IfCommand(&this->flightDataVariables, &this->commandMap)));
    //this->commandMap.insert(pair<string,Command*>("while",
    //        new WhileCommand(&this->flightDataVariables,&this->commandMap)));
    //this->commandMap.insert(pair<string,Command*>("print",new PrintCommand));
    this->commandMap.insert(pair<string, Command *>("var",
                                                    new VarCommand(&this->flightDataVariables)));
    //this->commandMap.insert(pair<string,Command*>("sleep",new SleepCommand));
}


/**
 * the function gets queue of commands, match each title to the actual command
 * and execute.
 * @param commandLine - reference to queue of strings that holds the commands
 */

void FlightController::parser(vector<string>::iterator &commandLine) {
    char i = commandLine->at(0);
    char end = commandLine->at(commandLine->size());
    while (i != end) {
        Command *command = commandMap.at(*commandLine);
        if (command == nullptr) {
            try { flightDataVariables.getVar(*commandLine); }
            catch (const char *exception) { throw "error, undefined command"; }
        } else {
            command->execute(commandLine);
        }
        ++i;
    }
}

/**
 * the function create new queue and call lexer and  parser
 * in order to interpret the input to command.
 */


void FlightController::interpreter() {
    vector<string> commandLine;
    Lexer lexer;
    if (this->isFile){
        lexer.splitFile(this->input, commandLine);
    } else {
        lexer.splitLine(this->input,commandLine);
    }
    vector<string>::iterator commandIt;
    commandIt = commandLine.begin();
    parser(commandIt);
}