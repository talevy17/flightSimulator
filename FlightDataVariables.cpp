#include "FlightDataVariables.h"

/**
* initialize the flight data map.
*/
void FlightDataVariables::flightDataInit() {
    this->flightData.insert(std::pair<string, double>("instrumentation/airspeed-indicator/indicated-speed-kt" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/altimeter/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/altimeter/pressure-alt-ft" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/attitude-indicator/indicated-pitch-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/attitude-indicator/indicated-roll-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/attitude-indicator/internal-pitch-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/attitude-indicator/internal-roll-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/encoder/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/encoder/pressure-alt-ft" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/gps/indicated-altitude-ft" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/gps/indicated-ground-speed-kt" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/gps/indicated-vertical-speed" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/heading-indicator/indicated-heading-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/magnetic-compass/indicated-heading-deg" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/slip-skid-ball/indicated-slip-skid" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/turn-indicator/indicated-turn-rate" ,0));
    this->flightData.insert(std::pair<string, double>("instrumentation/vertical-speed-indicator/indicated-speed-fpm" ,0));
    this->flightData.insert(std::pair<string, double>("controls/flight/aileron" ,0));
    this->flightData.insert(std::pair<string, double>("controls/flight/elevator" ,0));
    this->flightData.insert(std::pair<string, double>("controls/flight/rudder" ,0));
    this->flightData.insert(std::pair<string, double>("controls/flight/flaps" ,0));
    this->flightData.insert(std::pair<string, double>("controls/engines/current-engine/throttle" ,0));
    this->flightData.insert(std::pair<string, double>("engines/engine/rpm" ,0));
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

/**
* flight data getter.
* @return map<string , double> flightData.
*/
map<string, double> FlightDataVariables::getflightData() const {return this->flightData;}

/**
* value from the simulator getter.
* @param address string
* @return double value
*/
double FlightDataVariables::getValueAtAddress(string address) {
    try {
        return this->flightData.at(address);
    } catch (exception& e) {
        throw "address does not exist";
    }
}

void FlightDataVariables::setFlightData(vector<double> values) {
    this->flightData.at("instrumentation/airspeed-indicator/indicated-speed-kt") = values.at(0);
    this->flightData.at("instrumentation/altimeter/indicated-altitude-ft") = values.at(1);
    this->flightData.at("instrumentation/altimeter/pressure-alt-ft") = values.at(2);
    this->flightData.at("instrumentation/attitude-indicator/indicated-pitch-deg") = values.at(3);
    this->flightData.at("instrumentation/attitude-indicator/indicated-roll-deg") = values.at(4);
    this->flightData.at("instrumentation/attitude-indicator/internal-pitch-deg") = values.at(5);
    this->flightData.at("instrumentation/attitude-indicator/internal-roll-deg") = values.at(6);
    this->flightData.at("instrumentation/encoder/indicated-altitude-ft") = values.at(7);
    this->flightData.at("instrumentation/encoder/pressure-alt-ft") = values.at(8);
    this->flightData.at("instrumentation/gps/indicated-altitude-ft") = values.at(9);
    this->flightData.at("instrumentation/gps/indicated-ground-speed-kt") = values.at(10);
    this->flightData.at("instrumentation/gps/indicated-vertical-speed") = values.at(11);
    this->flightData.at("instrumentation/heading-indicator/indicated-heading-deg") = values.at(12);
    this->flightData.at("instrumentation/magnetic-compass/indicated-heading-deg") = values.at(13);
    this->flightData.at("instrumentation/slip-skid-ball/indicated-slip-skid") = values.at(14);
    this->flightData.at("instrumentation/turn-indicator/indicated-turn-rate") = values.at(15);
    this->flightData.at("instrumentation/vertical-speed-indicator/indicated-speed-fpm") = values.at(16);
    this->flightData.at("controls/flight/aileron") = values.at(17);
    this->flightData.at("controls/flight/elevator" ) = values.at(18);
    this->flightData.at("controls/flight/rudder") = values.at(19);
    this->flightData.at("controls/flight/flaps") = values.at(20);
    this->flightData.at("controls/engines/current-engine/throttle") = values.at(21);
    this->flightData.at("engines/engine/rpm") = values.at(22);
    for (auto it = this->flightData.begin(); it != this->flightData.end(); ++it) {
        if (this->binds.find(it->first) != this->binds.end()) {
            if (this->binds.at(it->first)->calculate() != it->second) {
                this->binds.at(it->first)->assignValueFromBindAddress(it->second);
            }
        }
    }
}

/**
 * DTOR, frees the allocated vars from the symbol table.
 */
FlightDataVariables::~FlightDataVariables() {
    auto it = this->symbolTable.begin();
    while (it != this->symbolTable.end()) {
        delete(it->second);
        it++;
    }
}