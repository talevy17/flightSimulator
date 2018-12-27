#include "SleepCommand.h"
#include "ShuntingYard.h"

SleepCommand ::SleepCommand(FlightDataVariables *dataVariables) {
    this->data = dataVariables;
}

void SleepCommand :: execute(vector<string>::iterator &it){
    ShuntingYard s(this->data->getSymbolTable());
    Expression* microseconds = s(++it);
    double microsec = microseconds -> calculate();
    usleep(microsec);
    it++;
}