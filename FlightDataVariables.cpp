//
// Created by tal on 12/20/18.
//

#include "FlightDataVariables.h"

/**
 * bind map getter.
 * @return map<string, Var*> binds
 */
map<string, Var*> FlightDataVariables::getBinds() const {return this->binds;}

/**
* symbol table getter.
* @return map<string, Var*> symbolTable.
*/
map<string, Var*> FlightDataVariables::getSymbolTable() const {return this->symbolTable;}

/**
 * add a new bind to the bind table
 * @param var the variable to be bound.
 */
void FlightDataVariables::addBind(Var *var) {
    this->binds.insert(std::pair<string, Var*>(var->getBindAddress(), var));
}

/**
 * add a new variable to the symbol table.
 * @param var
 */
void FlightDataVariables::addVar(Var *var) {
    this->symbolTable.insert(std::pair<string, Var*>(var->getName(), var));
}

/**
* specific var getter (when there's no need for the entire map)
* @param varName string
* @return Var* var.
*/
Var* FlightDataVariables::getVar(string varName) const {
    try {
        return this->symbolTable.at(varName);
    } catch (exception& e) {
        throw "Var does not exist";
    }
}

FlightDataVariables::~FlightDataVariables() {
    auto it = this->symbolTable.begin();
    while (it != this->symbolTable.end()) {
        delete(it->second);
        it++;
    }
}