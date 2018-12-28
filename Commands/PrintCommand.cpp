
#include "PrintCommand.h"

/**
* CTOR.
* @param vars
*/
PrintCommand::PrintCommand(FlightDataVariables *vars) {
    this->symbolTable = vars;
}

/**
* executes the command, prints the argument to the console.
* @param it
*/
void PrintCommand::execute(vector<string>::iterator &it) {
    it++;
    while (*it != ";") {
        if (it->at(0) == '"') {
            string toPrint = it->substr(1, it->size() - 2);
            cout << toPrint;
        } else {
            try {
                cout << this->symbolTable->getVar(*it)->calculate();
            } catch (exception& e) {
                throw "the variable that was sent to print does not exist!";
            }
        }
        it++;
        //progress the iterator only if it's a comma (means there are more arguments).
        if (*it == ",") {
            it++;
            cout << " ";
        }
    }
    cout << endl;
}