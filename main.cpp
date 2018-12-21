#include <iostream>
#include <string.h>
#include <vector>
#include "ShuntingYard.h"
#include "Lexer.h"

using namespace std;

int main (){
    vector<string> commandLine;
    commandLine.push_back("hi");
    commandLine.push_back("hello");
    commandLine.push_back("sh");
    vector<string> :: iterator it;
    string::iterator co;
    it = commandLine.begin();
    ++it;
    string i = *it;
    return 0;
}


