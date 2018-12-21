#include <fstream>
#include "FlightController.h"
#include "Lexer.h"


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
        //throw exception
        if (command==nullptr){perror("error, undefined command");}
        else {
            command->execute(commandLine);
        }
        ++i;
        ++commandLine;
    }
}


/**
 * constructor - gets file or command line, check if its file
 */
FlightController::FlightController(string str) {
    this->fileName = str;
    //check if the file exist
    ifstream file(str);
    if (!file.is_open()) { throw "error file not found"; }
}


/**
 * the function create new queue and call lexer and  parser
 * in order to interpret the input to command.
 */
void FlightController::interpreter() {
    vector<string> commandLine;
    Lexer lexer;
    //if file name is empty
    if (!this->fileName.compare("")) {
        //lexer.splitLine(this->lineOfCommands,commandLine);
    } else {
        lexer.splitFile(this->fileName, commandLine);
    }
    vector<string>::iterator commandIt;
    commandIt = commandLine.begin();
    parser(commandIt);
}
