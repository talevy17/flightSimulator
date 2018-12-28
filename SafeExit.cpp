#include "SafeExit.h"

/**
 * CTOR.
 * @param exit
 * @param ser
 * @param cl
 * @param cmdMap
 */
SafeExit::SafeExit(bool *exit, Server* ser, Client* cl, map<string, Command *>* cmdMap) {
    this->exit = exit;
    this->server = ser;
    this->client = cl;
    this->commandMap = cmdMap;
}

/**
 * frees all allocated memory and closes connections.
 * @param it
 */
void SafeExit :: execute(vector<string>:: iterator& it){
    this->server->closeServer();
    this->client->closeClient();
    delete(this->server);
    delete(this->client);
    for (auto it = this->commandMap->begin(); it != this->commandMap->end(); ++it) {
        delete (it->second);
    }
    *this->exit = true;
    it++;
}