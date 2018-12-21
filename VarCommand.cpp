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
        it++;
        try {
            var->bind(this->data->getVar(*it)->getBindAddress());
        } catch (const char* e){
            if (this->data->getflightData().find(*it) != this->data->getflightData().end()) {
                var->bind(*it);
            } else {
                throw "Invalid bind address";
            }
        }
        this->data->addBind(var);
        var->assignValueFromBindAddress(this->data->getValueAtAddress(var->getBindAddress()));
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