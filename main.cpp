#include <iostream>
#include <string.h>
#include "FlightDataVariables.h"
#include <vector>
#include "VarCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"

using namespace std;

vector<string>::iterator checkIter(vector<string>::iterator& src) {
    auto cpyIter = src;
    return cpyIter;
}

int main() {
    map<string, Command*> commands;
    FlightDataVariables data;
    data.flightDataInit();
    VarCommand v(&data);
    commands.insert(std::pair<string, Command*>("Var", &v));
    IfCommand f(&data, &commands);
    commands.insert(std::pair<string, Command*>("if", &f));
    WhileCommand w(&data, &commands);
    commands.insert(std::pair<string, Command*>("while", &w));
    vector<string> expression;
    expression.push_back("if");
    expression.push_back("z");
    expression.push_back("<");
    expression.push_back("y");
    expression.push_back(";");
    expression.push_back("{");
    expression.push_back("Var");
    expression.push_back("tal");
    expression.push_back("=");
    expression.push_back("5");
    expression.push_back(";");
    expression.push_back("while");
    expression.push_back("x");
    expression.push_back("<");
    expression.push_back("=");
    expression.push_back("y");
    expression.push_back(";");
    expression.push_back("{");
    expression.push_back("x");
    expression.push_back("=");
    expression.push_back("x");
    expression.push_back("+");
    expression.push_back("z");
    expression.push_back(";");
    expression.push_back("}");
    expression.push_back("}");
    Var* var = new Var("x", 0);
    data.addVar(var);
    var = new Var("y", 3);
    data.addVar(var);
    var = new Var("z", 1);
    data.addVar(var);
    auto it = expression.begin();
    try {
        f.execute(it);
        cout << "the first if var's name: " << data.getVar("tal")->getName() << ", the value is: " <<
        data.getVar("tal")->calculate() << endl;
        cout << "the var name is: " << data.getVar("x")->getName() <<
        ", the value is: " << data.getVar("x")->calculate() << endl;
    } catch (const char* e) {
        cout<<e<<endl;
    }
    return 0;
}