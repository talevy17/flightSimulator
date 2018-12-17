#include "ShuntingYard.h"
#include <stack>
#include <map>

Expression* extractNumber(string& expression, unsigned long int& index, long int size) {
    string number;
    bool isNeg = false;
    if (expression.at(index) == '-') {
        isNeg = true;
        index++;
    }
    while (index < size && expression.at(index) >= '0' && expression.at(index) <= '9') {
        number.push_back(expression.at(index));
        index++;
    }
    if (number.empty()) {
        throw "Invalid Expression";
    }
    if (isNeg) {
        return new Minus(new Number("0"), new Number(number));
    }
    return new Number(number);
}

void modifyExpression(stack<Expression*>& tokens, char op) {
    Expression* ex = tokens.top();
    tokens.pop();
    switch (op) {
        case '*':
            ex = new Mult(tokens.top(), ex);
            break;
        case '-':
            ex = new Minus(tokens.top(), ex);
            break;
        case '/':
            ex = new Div(tokens.top(), ex);
            break;
        case '+':
            ex = new Plus(tokens.top(), ex);
            break;
        default:
            throw "Invalid Expression";
    }
    tokens.pop();
    tokens.push(ex);
}

template<typename Comparator>
void flush (stack<Expression*>& tokens, stack<char>& ops, Comparator comp) {
    while (comp()) {
        modifyExpression(tokens, ops.top());
        ops.pop();
    }
}

Expression* parseExpression(string& expression) {
    stack<Expression*> tokens;
    stack<char> ops;
    map<char, int> precedence = {{'(',-1},{')', -2}, {'*', 2},{'/', 2}, {'+', 1}, {'-', 1}};
    long int size = expression.size();
    unsigned long int i = 0;
    bool parenthesis = false;
    while (i < size) {
        if (expression.at(i) == '(') {
            ops.push('(');
        } else {
            if (!parenthesis) {
                tokens.push(extractNumber(expression, i, size));
                if (i >= size) {
                    break;
                }
            } else {
                parenthesis = false;
            }
            int pred = precedence.at(expression.at(i));
            switch (pred) {
                case -2:
                    flush(tokens, ops, [&ops, &precedence]() {
                        return (!ops.empty() && precedence.at(ops.top()) != -1);});
                    if (ops.empty()) {
                        throw "Invalid Expression";
                    }
                    ops.pop();
                    parenthesis = true;
                    break;
                default:
                    flush(tokens, ops, [&ops, &precedence, &pred]() {
                        return (!ops.empty() && pred <= precedence.at(ops.top()) && precedence.at(ops.top()) > 0);});
                    ops.push(expression.at(i));
            }
        }
        i++;
    }
    flush(tokens, ops, [&ops]() {return !ops.empty();});
    return tokens.top();
}

double ShuntingYard::evaluate(string expression) {
    Expression* ex = parseExpression(expression);
    double value = ex->calculate();
    delete(ex);
    return value;
}