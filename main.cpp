#include <iostream>
#include <string.h>
#include "ShuntingYard.h"
using namespace std;

int main() {
    vector<string> expression;
    expression.push_back("5");
    expression.push_back("-");
    expression.push_back("2");
    expression.push_back("*");
    expression.push_back("(");
    expression.push_back("x");
    expression.push_back("+");
    expression.push_back("-");
    expression.push_back("24");
    expression.push_back(")");
    expression.push_back(";");
    Var* var = new Var("x", 2);
    map<string, Var*> varMap;
    varMap.insert(std::pair<string, Var*>("x", var));
    ShuntingYard s(varMap);
    auto it = expression.begin();
    Expression* ex;
    try {
        ex = s.parseExpression(it);
        cout << ex->calculate() <<endl;
    } catch (const char* e) {
        cout<<e<<endl;
    }
    return 0;
}