//
// Created by tal on 12/13/18.
//

#include "Number.h"

/**
 * CTOR, converts string input to double.
 * @param num string
 */
Number::Number(string num) {
    this->value = stod(num);
}

/**
* CTOR, by double.
* @param num
*/
Number::Number(double num) {this->value = num;}

/**
* calculates the expression.
* @return double value.
*/
double Number::calculate() const {return this->value;}