//
// Created by tal on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_FLIGHTDATAVARIABLES_H
#define FLIGHTSIMULATOR_FLIGHTDATAVARIABLES_H

#include "Var.h"
#include <map>

/**
 * responsible of keeping track of the variables and binds throughout the program.
 */
class FlightDataVariables {
    map<string, Var *> symbolTable;
    map<string, Var *> binds;
    map<string, double> flightData;
public:

    /**
     * initialize the flight data map.
     */
    void flightDataInit();

    /**
     * symbol table getter.
     * @return map<string, Var*> symbolTable.
     */
    map<string, Var *> getSymbolTable() const;

    /**
    * bind map getter.
    * @return map<string, Var*> binds
    */
    map<string, Var *> getBinds() const;

    /**
     * flight data getter.
     * @return map<string , double> flightData.
     */
    map<string, double> getflightData() const;

    /**
     * add a new variable to the symbol table.
     * @param var
     */
    void addVar(Var *var);

    /**
    * add a new bind to the bind table
    * @param var the variable to be bound.
    */
    void addBind(Var *var);

    /**
     * specific var getter (when there's no need for the entire map)
     * @param varName string
     * @return Var* var.
     */
    Var* getVar(string varName) const;

    double getValueAtAddress(string address);

    ~FlightDataVariables();
};


#endif //FLIGHTSIMULATOR_FLIGHTDATAVARIABLES_H
