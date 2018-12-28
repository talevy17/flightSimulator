#include <thread>
#include "SleepCommand.h"
#include "ShuntingYard.h"

SleepCommand ::SleepCommand(FlightDataVariables *dataVariables) {
    this->data = dataVariables;
}

void SleepCommand :: execute(vector<string>::iterator &it){
    ShuntingYard s(this->data->getSymbolTable());
    Expression* msec = s(++it);
    double sec = msec -> calculate();
    this_thread :: sleep_for(chrono::milliseconds(static_cast<int>(sec)));
    usleep(sec);
    it++;
}