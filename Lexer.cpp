#include "Lexer.h"
#include <sstream>
#include <fstream>
#include <bits/regex.h>

void splitLine(string line, queue<string> &commandLine){
    //int or float number,
    regex intOrFloat ("(/d)(.)*");
    //address
    regex address ("((/d)(.))+(/d)");
    //the optional operators
    regex operators ("[\\+|-|\\*|/]");
    //variable - String_(optional)String
    regex var ("(([A-Z][a-z])+_)+([A-Z][a-z])+");
    //optional expression
    regex exp (intOrFloat + operators + intOrFloat);
    //spaces
    regex space ("(/s)+ ,* ");
    //valid input
    regex s ("var (/s) intOrFloat ");
    regex

}








/*
#define SPACE ' '

void Lexer :: splitLine(const string line, queue<string> &commandLine){
    stringstream stream(line);
    string split;
    while (getline(stream, split, SPACE)) {
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
*/