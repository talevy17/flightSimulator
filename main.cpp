#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "FlightController.h"

using namespace std;

int main (int argc, char* argv[]) {
    FlightController fc;
    try {
        string i = argv[1];
        fc.controller(i, true);
    } catch (const char *e){
        perror(e);
    }
    return 0;
}