#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H

#include "Command.h"
#include "Data/FlightDataVariables.h"
#include "Sockets/Client.h"
#include "Interpreter/ShuntingYard.h"

class ConnectCommand : public Command {
    FlightDataVariables *data;
    Client* client;
public:
    ConnectCommand(FlightDataVariables *dataMaps, Client *client);
    void execute(vector<string>:: iterator& it) override;
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
