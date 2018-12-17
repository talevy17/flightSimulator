#ifndef FLIGHTSTIMULATOR_COMMAND_H
#define FLIGHTSTIMULATOR_COMMAND_H
#include <iostream>
#include <queue>

using namespace std;

class Command{
public:
    virtual void execute(queue<string> &commandLine);
};

#endif //FLIGHTSTIMULATOR_COMMAND_H
