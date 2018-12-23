#include "OpenDataServer.h"
#include "ShuntingYard.h"

OpenDataServer::OpenDataServer(FlightDataVariables& dataMaps) :data(dataMaps) {}

void* socketRead(void* pVoid) {
    auto* params = (OpenDataServer::socketParameters*) pVoid;
    while (true) {
        auto x = params->ser->socketReader(params->sockfd);
        if (x == "exit") {
            break;
        }
    }
    return nullptr;
}

void StartThread(OpenDataServer:: socketParameters* params) {
    pthread_t trid;
    params->sockfd = params->ser->openServer(params->port, params->hz);
    pthread_create(&trid, nullptr, socketRead, params);
}


void OpenDataServer::execute(vector<string>::iterator &it) {
    ShuntingYard s(this->data.getSymbolTable());
    Server server(this->data);
    double port, time;
    //try parsing the variables.
    try {
        Expression* portEx = s(++it);
        Expression* hzEx = s(++it);
        port = portEx->calculate();
        time = hzEx->calculate();
        delete(portEx);
        delete(hzEx);
    } catch (const out_of_range &no_such_var) {
        //the Expressions were invalid.
        __throw_runtime_error("invalid params to OpenDataServer Command");
    } // if port or time are negative
    if (port < 0 || time < 0) {
        __throw_runtime_error("invalid (neg) params to OpenDataServer");
    }
    // initialize the parameter struct for the socket.
    socketParameters params = {(int) port, (int) time, &server};
    it++;
    StartThread(&params); // open new thread
}