//
// Created by tal on 12/20/18.
//

#include "VarCommand.h"
#include "ShuntingYard.h"

VarCommand::VarCommand(FlightDataVariables* maps) {
    this->data = maps;
}

void VarCommand::execute(vector<string>::iterator& it) {
    Var* var;
    if (*it == "Var") {
        var = new Var(*(++it));
        this->data->addVar(var);
        ++it;
    } else {
        try {
            var = this->data->getVar(*it);
            if (*(++it) != "=") {
                throw "Invalid command!";
            }
        } catch (const char* ex) {
            throw ex;
        }
    }
    if (*it != "=") {
        return;
    }
    if (*(++it) == "bind") {
        var->bind(*(++it));
        this->data->addBind(var);
        ++it;
    } else {
        ShuntingYard s(this->data->getSymbolTable());
        try {
            var->assignValue(s(it));
        } catch (const char* ex) {
            throw ex;
        }
    }
    if (*it != ";") {
        throw "Invalid command line!";
    }
}