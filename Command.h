#ifndef FLIGHTSTIMULATOR_COMMAND_H
#define FLIGHTSTIMULATOR_COMMAND_H
#include <iostream>
#include <vector>


using namespace std;

class Command{
public:
    virtual void execute(vector<string>::iterator &commandLine) {

    }
};

#endif //FLIGHTSTIMULATOR_COMMAND_H
