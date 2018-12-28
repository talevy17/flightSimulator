
#include "Var.h"


/**
* CTOR.
* @param varName string name
* @param val double value
*/
Var::Var(string varName, double val, Client *client, mutex &m)
        : _mutex(m) {
    this->value = val;
    this->name = varName;
    this->client = client;
}

/**
* CTOR.
* @param varName string name
*/
Var::Var(string varName, Client *client, mutex &m)
        : _mutex(m) {
    this->name = varName;
    this->client = client;
}

/**
* name getter.
* @return string name.
*/
string Var::getName() const { return this->name; }

/**
* assign a value to the Var, shall be used by the assign command at run-time.
* @param val
*/
void Var::assignValue(double val) {
    this->value = val;
    //update value.
    unique_lock<mutex> ul(this->_mutex);
    if (!this->bindAddress.empty()) {
        this->client->send(this->bindAddress, val);
    }
    ul.unlock();
}

/**
* assign a value of an Expression to the var, shall be used by the assign command.
* @param ex
*/
void Var::assignValue(Expression *ex) {
    double d = ex->calculate();
    assignValue(d);
    delete (ex);
}

/**
* bind address getter.
* @return
*/
string Var::getBindAddress() const { return this->bindAddress; }

/**
* sets the binding address.
* @param address
*/
void Var::bind(string address) {
    this->bindAddress = address;
}

/**
* in case of an update from the simulator, updates the value without resetting the value in the simulator.
* @param val double value from flight data map.
*/
void Var::assignValueFromBindAddress(double val) {
    unique_lock<mutex> ul(this->_mutex);
    this->value = val;
    ul.unlock();
}

/**
* calculates the value of the node.
* @return double value.
*/
double Var::calculate() const { return this->value; }