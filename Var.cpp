
#include "Var.h"

/**
* CTOR.
* @param varName string name
* @param val double value
*/
Var::Var(string varName, double val) {
    this->value = val;
    this->name = varName;
}

/**
* CTOR.
* @param varName string name
*/
Var::Var(string varName) {
    this->name = varName;
}

/**
* name getter.
* @return string name.
*/
string Var::getName() const {return this->name;}

/**
* assign a value to the Var, shall be used by the assign command at run-time.
* @param val
*/
void Var::assignValue(double val) {
    this->value = val;
    //if bind...
}

/**
* assign a value of an Expression to the var, shall be used by the assign command.
* @param ex
*/
void Var::assignValue(Expression *ex) {
    assignValue(ex->calculate());
    delete(ex);
}

/**
* bind address getter.
* @return
*/
string Var::getBindAddress() const {return this->bindAddress;}

/**
* sets the binding address.
* @param address
*/
void Var::bind(string address) {this->bindAddress = address;}

/**
* in case of an update from the simulator, updates the value without resetting the value in the simulator.
* @param val double value from flight data map.
*/
void Var::assignValueFromBindAddress(double val) {this->value = val;}

/**
* calculates the value of the node.
* @return double value.
*/
double Var::calculate() const { return this->value;}