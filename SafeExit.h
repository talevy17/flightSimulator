#ifndef FLIGHTSIMULATOR_SAFEEXIT_H
#define FLIGHTSIMULATOR_SAFEEXIT_H


#include "Command.h"

class SafeExit : public Command {
    bool *exit;
public:
    SafeExit(bool *exit);
    void execute(vector<string>:: iterator& it);
};


#endif //FLIGHTSIMULATOR_SAFEEXIT_H
