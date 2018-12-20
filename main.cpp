#include <iostream>
#include <string.h>
#include "FlightDataVariables.h"
#include <vector>
#include "VarCommand.h"
using namespace std;

int main() {
    FlightDataVariables data;
    VarCommand v(&data);
    vector<string> expression;
    expression.push_back("Var");
    expression.push_back("karin");
    expression.push_back("=");
    expression.push_back("bind");
    expression.push_back("/home/karin/CLionProjects/");
    expression.push_back(";");
    Var* var = new Var("x", 2);
    data.addVar(var);
    auto it = expression.begin();
    try {
        v.execute(it);
        cout << "the var name is: " << data.getVar("karin")->getName() <<
        ", the bind address is: " << data.getVar("karin")->getBindAddress() << endl;
    } catch (const char* e) {
        cout<<e<<endl;
    }
    return 0;
}