#include <iostream>
#include <string.h>
#include "ShuntingYard.h"
using namespace std;

int main() {
    queue<string> expression;
    expression.push("5");
    expression.push("-");
    expression.push("2");
    expression.push("*");
    expression.push("(");
    expression.push("x");
    expression.push("+");
    expression.push("-");
    expression.push("24");
    expression.push(")");
    Var* var = new Var("x", 2);
    map<string, Var*> varMap;
    varMap.insert(std::pair<string, Var*>("x", var));
    ShuntingYard s(expression, varMap);
    Expression* ex = s.parseExpression();
    cout << ex->calculate() <<endl;
    return 0;
}