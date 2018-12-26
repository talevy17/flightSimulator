#include "OpenDataServer.h"
#include "ShuntingYard.h"

OpenDataServer::OpenDataServer(Server& ser, FlightDataVariables& dataMaps) :server(ser), data(dataMaps) {}

void socketRead(Server* server) {
    while (true) {
        auto x = server->socketReader();
        if (x == "exit") {
            break;
        }
    }
}

void OpenDataServer::execute(vector<string>::iterator &it) {
    ShuntingYard s(this->data.getSymbolTable());
    double port, time;
    //try parsing the variables.
    try {
        Expression* portEx = s(++it);
        Expression* hzEx = s(++it);
        port = portEx->calculate();
        time = hzEx->calculate();
        delete(portEx);
        delete(hzEx);
    } catch (const char* &e) {
        //the Expressions were invalid.
        __throw_runtime_error("invalid params to OpenDataServer Command");
    } // if port or time are negative
    if (port < 0 || time < 0) {
        __throw_runtime_error("invalid (neg) params to OpenDataServer");
    }
    // initialize the parameter struct for the socket.
    it++;
    this->server.openServer((int) port, (int) time);
    thread ser(socketRead, &this->server);
    ser.detach();
}