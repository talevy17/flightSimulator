#include <thread>
#include "SleepCommand.h"
#include "ShuntingYard.h"

/**
 * constructor
 * @param dataVariables
 */
SleepCommand ::SleepCommand(FlightDataVariables *dataVariables) {
    this->data = dataVariables;
}

/**
 * the function gets iterator and command of sleep
 * and sleep for the number of seconds.
 * @param it iterator of commands
 */
void SleepCommand :: execute(vector<string>::iterator &it){
    ShuntingYard s(this->data->getSymbolTable());
    Expression* msec = s(++it);
    double sec = msec -> calculate();
    this_thread :: sleep_for(chrono::milliseconds(static_cast<int>(sec)));
    usleep(sec);
    it++;
}