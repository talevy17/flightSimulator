#ifndef FLIGHTSTIMULATOR_COMMAND_H
#define FLIGHTSTIMULATOR_COMMAND_H
#include <iostream>
#include <queue>

using namespace std;

class Command{
public:
    virtual void execute(vector<string>:: iterator it) = 0;
};

#endif //FLIGHTSTIMULATOR_COMMAND_H
