#ifndef FLIGHTSTIMULATOR_LEXER_H
#define FLIGHTSTIMULATOR_LEXER_H
#include <queue>
#include <string>

using namespace std;

class Lexer {
public:
    void splitLine(string line, vector<string> &commandLine);
    void splitFile(string fileName, vector<string> &commandLine);
};


#endif //FLIGHTSTIMULATOR_LEXER_H