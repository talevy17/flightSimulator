#include "Lexer.h"
#include <sstream>
#include <fstream>
#include <regex>

//var_name
//number
//space
//string ""


void splitLine(string line, queue<string> &commandLine){
    //variable - String_(optional)String
    regex var ("[A-Z][a-z]+ (_)? [A-Z][a-z]+");
    //int or float number
    regex intOrFloat ("(-)?(/s)*(/d)((\\.)(/d))? (/s)*");
    //the optional operators
    regex operators ("[\\+|-|\\*|/]");

    //spaces
    regex space ("[:s:]+");
    //valid input
    //regex s (var "(/s)" intOrFloat);


    //optional expression - waits for syntax
    regex exp ("(-)?(/s)*(/d)((\\.)(/d))?(/s)* [+|-|*|/] (-)?(/s)*(/d)((\\.)(/d))?");

}

void Lexer :: splitLine(const string line, queue<string> &commandLine){
    stringstream stream(line);
    string split;
    while (getline(stream, split, ' ')) {
        commandLine.push(split);
    }
}

void Lexer :: splitFile(const string fileName, queue<string> &commandLine){
    ifstream file(fileName);
    if (!file.is_open()){throw "error file not found";}
    string line;
    while (getline(file,line)){
        splitLine(line,commandLine);
    }
}