#include "OpenDataServer.h"
#include "ShuntingYard.h"

pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

OpenDataServer::OpenDataServer(FlightDataVariables& dataMaps) : data(dataMaps) {}

void* socketRead(void* pVoid) {
    auto* params = (OpenDataServer::socketParameters*) pVoid;
    while (true) {
        pthread_mutex_lock(&lock2);
        auto x = params->ser->socketReader(params->sockfd);
        if (x == "exit") {
            break;
        }
        pthread_mutex_unlock(&lock2);
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
    } catch (const char* &e) {
        //the Expressions were invalid.
        __throw_runtime_error("invalid params to OpenDataServer Command");
    } // if port or time are negative
    if (port < 0 || time < 0) {
        __throw_runtime_error("invalid (neg) params to OpenDataServer");
    }
    // initialize the parameter struct for the socket.
    this->params.port = (int) port;
    this->params.hz = (int) time;
    this->params.ser = &(server);
    it++;
    StartThread(&this->params); // open new thread
}