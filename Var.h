

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <string>
#include "Expression.h"
#include "Client.h"

/**
 * A single variable, a node in the expression design pattern.
 */
class Var : public Expression {
    string name;
    string bindAddress;
    double value;
    Client* client;
    mutex &_mutex;
public:
    /**
     * CTOR.
     * @param varName string name
     * @param val double value
     */
    Var(string varName, double val, Client *client, mutex &m);

    /**
     * CTOR.
     * @param varName string name
     */
    Var(string varName, Client *client, mutex &m);

    /**
     * name getter.
     * @return string name.
     */
    string getName() const;

    /**
     * sets the binding address.
     * @param address
     */
    void bind(string address);

    /**
     * bind address getter.
     * @return
     */
    string getBindAddress() const;

    /**
     * assign a value to the Var, shall be used by the var command at run-time.
     * @param val
     */
    void assignValue(double val);

    /**
     * assign a value of an Expression to the var, shall be used by the var command.
     * @param ex
     */
    void assignValue(Expression* ex);

    /**
     * in case of an update from the simulator, updates the value without resetting the value in the simulator.
     * @param val double value from flight data map.
     */
    void assignValueFromBindAddress(double val);

    /**
     * calculates the value of the node.
     * @return double value.
     */
    double calculate() const;

    /**
     * DTOR.
     */
    ~Var(){}
};


#endif //FLIGHTSIMULATOR_VAR_H
