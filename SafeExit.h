#ifndef FLIGHTSIMULATOR_SAFEEXIT_H
#define FLIGHTSIMULATOR_SAFEEXIT_H

#include "Command.h"
#include "Server.h"
#include "Client.h"

class SafeExit : public Command {
    bool *exit;
    Server* server;
    Client* client;
    map<string, Command *>* commandMap;
public:
    /**
    * CTOR.
    * @param exit
    * @param ser
    * @param cl
    * @param cmdMap
    */
    SafeExit(bool *exit, Server* ser, Client* cl, map<string, Command *>* cmdMap);
    /**
    * frees all allocated memory and closes connections.
    * @param it
    */
    void execute(vector<string>:: iterator& it);
};


#endif //FLIGHTSIMULATOR_SAFEEXIT_H
