#ifndef FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H
#define FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H

#include <iostream>
#include <map>
#include <vector>
#include "Command.h"
#include "Var.h"
#include "FlightDataVariables.h"
#include "VarCommand.h"
#include "OpenDataServer.h"
#include "IfCommand.h"
#include "WhileCommand.h"
//#include "ConnectCommand.h"
//#include "PrintCommand.h"

using namespace std;

class FlightController {
    map<string, Command *> commandMap;
    FlightDataVariables flightDataVariables;
    string input;
    bool isFile;

public:
    FlightController();

    void controller(string input, bool isFile);

    void initializeCommandMap();

    void parser(vector<string> &commandLine);

    ~FlightController() {

    }
};


#endif //FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H