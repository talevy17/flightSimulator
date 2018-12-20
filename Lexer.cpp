#include "Lexer.h"
#include <algorithm>
#include <fstream>
#define SPACE ' '
#define END_OF_ROW ";"

using namespace std;


void Lexer :: splitLine(string line, vector<string> &commandLine) {
    size_t begin = 0, end;
    line.push_back(' ');
    while ((end = line.find_first_of("\", *+-<>=()/, \n")) != string::npos
           && begin <= end ) {
        if (line.at(end) == '\"'){
            size_t endAdress = line.find_first_of(SPACE);
            commandLine.push_back(line.substr(begin, endAdress));
            line.clear();
            break;
        }else {
            if (begin == end && end < line.size() && line.at(end) != SPACE) {
                end = 1;
            }
            commandLine.push_back(line.substr(begin, end));
            if (line.at(end) == SPACE|| line.at(end)== '\n') {
                commandLine.emplace_back(",");
                end++;
            }
        }
        line = line.substr(end, line.size());
    }
    if (line.size() > 0) {
        commandLine.push_back(line.substr(0, line.size()));
    }
    commandLine.emplace_back(END_OF_ROW);

}


void Lexer :: splitFile(const string fileName, vector<string> &commandLine){
    ifstream file(fileName);
    if (!file.is_open()){throw "error file not found";}
    string line;
    while (getline(file,line)){
        splitLine(line,commandLine);
    }
}