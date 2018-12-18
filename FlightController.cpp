#include <fstream>
#include "FlightController.h"
#include "Lexer.h"

/**
 * constructor - gets file or command line, check if its file
 */
FlightController :: FlightController (string str){
    //initialize maps using the default constructor
    this->commandMap;
    this->variablesMap;
    //check if the file exist
    ifstream file(str);
    if (!file.is_open()){throw "error file not found";}
    this->fileName = fileName;
}


/**
 * the function gets queue of commands, match each title to the actual command
 * and execute.
 * @param commandLine - reference to queue of strings that holds the commands
 */
void FlightController :: parser (queue<string> &commandLine){
    while (!commandLine.empty()){
        //match string to command
        Command* command = commandMap.at(commandLine.front());
        commandLine.pop();
        if (command== NULL){throw "error, undefined command";}
        else {

            command->execute(commandLine);
        }
    }
}


/**
 * the function create new queue and call lexer and  parser
 * in order to interpret the input to command.
 */
void FlightController :: interpreter(){
    queue<string> commandLine;
    Lexer lexer;
    //if file name is empty
    if (!this->fileName.compare("")){
        //lexer.splitLine(this->lineOfCommands,commandLine);
    } else {
        lexer.splitFile(this->fileName,commandLine);
    }
    parser(commandLine);
}