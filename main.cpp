#include <iostream>
#include <string.h>
#include <vector>
#include "ShuntingYard.h"
#include "Lexer.h"

using namespace std;

int main (){
    /*
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
=======
#include "FlightDataVariables.h"
#include <vector>
#include "VarCommand.h"
#include "IfCommand.h"
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
    expression.push_back("if");
    expression.push_back("x");
    expression.push_back("=");
    expression.push_back("=");
    expression.push_back("y");
    expression.push_back(";");
    expression.push_back("{");
    expression.push_back("Var");
    expression.push_back("karin");
    expression.push_back("=");
    expression.push_back("bind");
    expression.push_back("/engines/engine/rpm");
    expression.push_back(";");
    expression.push_back("}");
    expression.push_back("}");
    Var* var = new Var("x", 3);
    data.addVar(var);
    var = new Var("y", 3);
    data.addVar(var);
    var = new Var("z", 0);
    data.addVar(var);
    auto it = expression.begin();
    try {
        f.execute(it);
        cout << "the first if var's name: " << data.getVar("tal")->getName() << ", the value is: " <<
        data.getVar("tal")->calculate() << endl;
        cout << "the var name is: " << data.getVar("karin")->getName() <<
        ", the bind address is: " << data.getVar("karin")->getBindAddress() << endl;
    } catch (const char* e) {
        cout<<e<<endl;
    }
>>>>>>> 487e9c80e1903ab472e775a6e6c5e5c42ab523f4
*/
    string s = "talBatal";
    string t = s.substr(0,s.size()-1);
    return 0;
}


