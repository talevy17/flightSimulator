#include <iostream>
#include "Interpreter/FlightController.h"

using namespace std;

/**
 * the main function gets file name and call flight controller
 * @param argc
 * @param argv
 * @return int 0 - for success
 */
int main(int argc, char *argv[]) {
    //run until "exit" command change it
    bool stop = false;
    FlightController fc(&stop);
    try {
        string fileName = argv[1];
        fc.controller(fileName, true);
    } catch (const char *e) {
        perror(e);
    }
    while (!stop) {}
    return 0;
}