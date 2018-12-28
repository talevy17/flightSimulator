//
// Created by tal on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "Command.h"
#include "Data/FlightDataVariables.h"
#include "Sockets/Client.h"

class VarCommand : public Command {
    FlightDataVariables *data;
    Client* client;
    mutex &_mutex;
public:
    /**
     * CTOR, receives access to the data maps.
     * @param maps
     */
    VarCommand(FlightDataVariables *maps, Client *client, mutex &m);

    /**
     * execute the Var Command (implements the command design pattern).
     * @param it
     */
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
