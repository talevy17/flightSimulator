#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(FlightDataVariables &dataMaps) : data(dataMaps) {}

void ConnectCommand::execute(vector<string>::iterator &it) {
    ShuntingYard s(this->data.getSymbolTable());
    string ip = *(++it);
    it++;
    Expression *port = s(++it);
    double dport = port->calculate();
    Client cl;
    cl.openClient(ip, dport);
    it++;
}
