#include <thread>
#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(FlightDataVariables &dataMaps, Client &client) :
data(dataMaps){
    this->client = client;
}

void ConnectCommand::execute(vector<string>::iterator &it) {
    ShuntingYard s(this->data.getSymbolTable());
    string ip = *(++it);
    it++;
    Expression *port = s(++it);
    double dport = port->calculate();
    this->client.openClient(ip, dport);
    //////send string
//    thread cln(client.send(,this->data), &client);
//    cln.detach();
    it++;
}
