//
// Created by karin on 12/13/18.
//

#ifndef FLIGHTSTIMULATOR_LEXER_H
#define FLIGHTSTIMULATOR_LEXER_H
#include <queue>
#include <string>

using namespace std;

class Lexer {
public:
    void splitLine(string line, queue<string> &commandLine);
    void splitFile(string fileName, queue<string> &commandLine);
};


#endif //FLIGHTSTIMULATOR_LEXER_H
