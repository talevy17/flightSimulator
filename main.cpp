#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "FlightController.h"
#include "PrintCommand.h"
#include <mutex>

using namespace std;

/*
int main (int argc, char* argv[]) {
    FlightController fc;
    try {
        string i = argv[1];
        fc.controller(i, true);
    } catch (const char *e){
        perror(e);
    }
    return 0;
}
*/
int main() {
    map<string, Command *> commands;
    FlightDataVariables data;
    mutex _m;
    Server server(_m, data);
    data.flightDataInit();
    VarCommand v(&data);
    commands.insert(std::pair<string, Command *>("var", &v));
    IfCommand f(&data, &commands);
    commands.insert(std::pair<string, Command *>("if", &f));
    WhileCommand w(&data, &commands);
    commands.insert(std::pair<string, Command *>("while", &w));
    PrintCommand p(&data);
    commands.insert(std::pair<string, Command*>("print", &p));
    OpenDataServer ser(server,data);
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
    server.closeServer();
}

