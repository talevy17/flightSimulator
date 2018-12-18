#include "ShuntingYard.h"
#include <stack>
#include <map>

#define SPACE ' '

/**
 * extracts a number from the input string at the current index.
 * @param expression string
 * @param index long int current index
 * @param size long int expression's size
 * @return Expression* number
 */
Expression *extractNumber(string &expression, unsigned long int &index, long int size) {
    //save the result.
    string number;
    //negative flag.
    bool isNeg = false;
    //if the number is negative, toggle the flag.
    if (expression.at(index) == '-') {
        isNeg = true;
        index++;
    }
    //ignore white spaces.
    while (expression.at(index) == SPACE) {
        index++;
    }
    //while you see digits.
    while (index < size && ((expression.at(index) >= '0' && expression.at(index) <= '9') ||
            (expression.at(index) == '.'))) {
        number.push_back(expression.at(index));
        index++;
    }
    //avoid skipping an index in the outside loop.
    index--;
    //if no digits were added, the string does not represent a number.
    if (number.empty()) {
        throw "Invalid Expression";
    }
    if (isNeg) {
        //"negate" the number (0-num = -num).
        return new Minus(new Number("0"), new Number(number));
    }
    return new Number(number);
}

/**
 * modify two expressions into a new binary expressions with the given operation.
 * @param tokens the stack of expressions.
 * @param op the operator.
 */
void modifyExpression(stack<Expression *> &tokens, char op) {
    //set ex to point to the right argument.
    Expression *ex = tokens.top();
    //pop the right argument.
    tokens.pop();
    //switch the operation, the left argument is topping the stack.
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
    //pop the left argument
    tokens.pop();
    //push the modified expression.
    tokens.push(ex);
}

/**
 * flush the stack while the comp condition applies, modify the expression by the operator.
 * @tparam Comparator comparing template class.
 * @param tokens the expressions stack.
 * @param ops the operators stack.
 * @param comp comparing lambda object function.
 */
template<typename Comparator>
void flush(stack<Expression *> &tokens, stack<char> &ops, Comparator comp) {
    while (comp()) {
        modifyExpression(tokens, ops.top());
        ops.pop();
    }
}

/**
 * parse a string to Expression* using Dijkstra's Shunting-Yard algorithm.
 * @param expression the string input expression.
 * @return Expression* result.
 */
Expression *parseExpression(string &expression) {
    //expressions stack.
    stack<Expression *> tokens;
    //operators stack.
    stack<char> ops;
    //boolean flag, to determine if the format is valid (tell between negative numbers and Minus operator).
    bool insertedToken = false;
    //precedence map that applies the precedence laws of simple math.
    map<char, int> precedence = {{'*', 2},{'/', 2},{'+', 1},{'-', 1},{'(', -1}};
    //the expression's size.
    long int size = expression.size();
    //loop's index.
    unsigned long int i = 0;
    //scan the expression once.
    while (i < size) {
        char curr = expression.at(i);
        switch (curr) {
            case '(':
                ops.push(expression.at(i));
                break;
            case ')':
                //flush until the opening bracket is found.
                flush(tokens, ops, [&ops]() { return (!ops.empty() && ops.top() != '('); });
                //if there wasn't an opening bracket - the expression is invalid.
                if (ops.empty()) {
                    throw "Invalid Expression";
                }
                //pop the bracket.
                ops.pop();
                break;
            case SPACE:
                //skip spaces.
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                //check if there's a number inserted as left a argument.
                if (insertedToken) {
                    //flush until there are no more operators with higher precedence in the stack.
                    flush(tokens, ops, [&ops, &precedence, &curr]() {
                        return (!ops.empty() && precedence.at(curr) <= precedence.at(ops.top()));});
                    ops.push(expression.at(i));
                    //expect a number (or a bracket) after this.
                    insertedToken = false;
                    break;
                } // else go straight to default and scan the next number.
            default:
                tokens.push(extractNumber(expression, i, size));
                insertedToken = true;
        }
        i++;
    } // end of while block.
    //flush the remaining operators in the operators stack.
    flush(tokens, ops, [&ops]() { return !ops.empty(); });
    //return the parsed expression.
    return tokens.top();
}

/**
 * evaluate the input string expression, throws exception if the expression is invalid.
 * @param expression the string expression.
 * @return double result.
 */
double ShuntingYard::evaluate(string expression) {
    Expression *ex = parseExpression(expression);
    double value = ex->calculate();
    delete (ex);
    return value;
}