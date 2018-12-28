#ifndef FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H
#define FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H

#include <iostream>
#include <map>
#include <vector>
#include "Commands/Command.h"
#include "Expressions/Var.h"
#include "Data/FlightDataVariables.h"
#include "Commands/VarCommand.h"
#include "Commands/OpenDataServer.h"
#include "Commands/IfCommand.h"
#include "Commands/WhileCommand.h"
#include "Lexer.h"
#include "Commands/PrintCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/SleepCommand.h"
#include "Commands/SafeExit.h"
#include "Expressions/CommandExpression.h"

using namespace std;

class FlightController {
    map<string, Command *> commandMap;
    FlightDataVariables flightDataVariables;
    Server* server;
    Client* client;
    bool *shouldStop;

public:
    explicit FlightController(bool *stop);

    void controller(string input, bool isFile);

    void initializeCommandMap();

    void parser(vector<string> &commandLine);

    ~FlightController();
};


#endif //FLIGHTSTIMULATOR_FLIGHTCONTROLLER_H