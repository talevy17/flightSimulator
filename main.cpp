#include <iostream>
#include <string.h>
#include <vector>
#include "ShuntingYard.h"
#include "Lexer.h"

using namespace std;

/*int main (){

}
    vector<string> commandLine;
    commandLine.push_back("hi");
    commandLine.push_back("hello");
    commandLine.push_back("sh");
    vector<string> :: iterator it;
    string::iterator co;
    it = commandLine.begin();
    ++it;
    string i = *it;
=======*/
#include "FlightDataVariables.h"
#include <vector>
#include "VarCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "PrintCommand.h"
#include "OpenDataServer.h"

using namespace std;

vector<string>::iterator checkIter(vector<string>::iterator& src) {
    auto cpyIter = src;
    return cpyIter;
}

int main() {
    map<string, Command *> commands;
    FlightDataVariables data;
    data.flightDataInit();
    VarCommand v(&data);
    commands.insert(std::pair<string, Command *>("var", &v));
    IfCommand f(&data, &commands);
    commands.insert(std::pair<string, Command *>("if", &f));
    WhileCommand w(&data, &commands);
    commands.insert(std::pair<string, Command *>("while", &w));
    PrintCommand p(&data);
    commands.insert(std::pair<string, Command*>("print", &p));
    OpenDataServer ser(data);
    commands.insert((std::pair<string, Command*>("openDataServer", &ser)));
    vector<string> expression;
    expression.push_back("openDataServer");
    expression.push_back("5400");
    expression.push_back(",");
    expression.push_back("10");
    expression.push_back(";");
    expression.push_back("var");
    expression.push_back("tal");
    expression.push_back("=");
    expression.push_back("bind");
    expression.push_back("\"/engines/engine/rpm\"");
    expression.push_back(";");
    expression.push_back("print");
    expression.push_back("tal");
    expression.push_back(";");
    auto it = expression.begin();
    try {
        ser.execute(it);
        v.execute(it);
        p.execute(it);
        cout << "the first if var's name: " << data.getVar("tal")->getName() << ", the value is: " <<
             data.getVar("tal")->calculate() << endl;
    } catch (const char *e) {
        cout << e << endl;
    }
}
