#ifndef FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H
#define FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H

#include "Command.h"
#include <iostream>
#include <map>
#include <vector>
#include "Var.h"

using namespace std;

class FlightController {
    map<string,Command*> commandMap;
    map<string,Var*> variablesMap;
    string fileName;
public:
    /*FlightController(string str);
    void parser(vector<string> &commandLine);
    void interpreter();*/

};


#endif //FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H