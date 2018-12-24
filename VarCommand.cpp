//
// Created by tal on 12/20/18.
//

#include "VarCommand.h"
#include "ShuntingYard.h"

/**
* CTOR, receives access to the data maps.
* @param maps
*/
VarCommand::VarCommand(FlightDataVariables *maps) {
    this->data = maps;
}

/**
* execute the Var Command (implements the command design pattern).
* @param it
*/
void VarCommand::execute(vector<string>::iterator &it) {
    Var *var;
    //check if the command was called to create a new variable.
    if (*it == "var") {
        var = new Var(*(++it));
        this->data->addVar(var);
        ++it;
        //it's not a creation, it's an assignment.
    } else {
        try {
            var = this->data->getVar(*it);
            //assignment without an assign operator is invalid.
            if (*(++it) != "=") {
                throw "Invalid command!";
            }
        } catch (const char *ex) {
            throw ex;
        }
    }
    //in case it was a blank creation.
    if (*it != "=") {
        if (*it != ";") {
            throw "Invalid command line!";
        }
        return;
    }
    //distinguish between binding and assigning a value.
    if (*(++it) == "bind") {
        if ((*(++it)).at(0) == '"') {
            string address = (*it).substr(1, (*it).size() - 2);
            var->bind(address);
        } else {
            var->bind(*it);
        }
        //add the bind and assign the current value from the simulator.
        this->data->addBind(var);
        var->assignValueFromBindAddress(this->data->getValueAtAddress(var->getBindAddress()));
        ++it;
        //it's an assignment, evaluate the expression and assign.
    } else {
        ShuntingYard s(this->data->getSymbolTable());
        try {
            var->assignValue(s(it));
        } catch (const char *ex) {
            throw ex;
        }
    }
    //if the command line hasn't reached the end the command is invalid.
    if (*it != ";") {
        throw "Invalid command line!";
    }
    it++;
}