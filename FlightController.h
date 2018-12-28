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
#include "Lexer.h"
#include "OpenDataServer.h"
#include "PrintCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"
#include "SafeExit.h"
#include "CommandExpression.h"

using namespace std;

class FlightController {
    map<string, Command *> commandMap;
    FlightDataVariables flightDataVariables;
    Server* server;
    Client* client;
    bool *shouldStop;

public:
    FlightController(bool *stop);

    void controller(string input, bool isFile);

    void initializeCommandMap();

    void parser(vector<string> &commandLine);

    ~FlightController() {

    }
};


#endif //FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H