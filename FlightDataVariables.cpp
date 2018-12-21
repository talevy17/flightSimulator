//
// Created by tal on 12/20/18.
//

#include "FlightDataVariables.h"

/**
* initialize the flight data map.
*/
void FlightDataVariables::flightDataInit() {
    this->flightData.insert(std::pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/altimeter/pressure-alt-ft" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/encoder/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/encoder/pressure-alt-ft" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/gps/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/gps/indicated-vertical-speed" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate" ,0));
    this->flightData.insert(std::pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm" ,0));
    this->flightData.insert(std::pair<string, double>("/controls/flight/aileron" ,0));
    this->flightData.insert(std::pair<string, double>("/controls/flight/elevator" ,0));
    this->flightData.insert(std::pair<string, double>("/controls/flight/rudder" ,0));
    this->flightData.insert(std::pair<string, double>("/controls/flight/flaps" ,0));
    this->flightData.insert(std::pair<string, double>("/controls/engines/engine/throttle" ,0));
    this->flightData.insert(std::pair<string, double>("/engines/engine/rpm" ,0));
}

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

map<string, double> FlightDataVariables::getflightData() const {return this->flightData;}

double FlightDataVariables::getValueAtAddress(string address) {
    try {
        return this->flightData.at(address);
    } catch (exception& e) {
        throw "address does not exist";
    }
}

FlightDataVariables::~FlightDataVariables() {
    auto it = this->symbolTable.begin();
    while (it != this->symbolTable.end()) {
        delete(it->second);
        it++;
    }
}