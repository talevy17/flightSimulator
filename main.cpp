#include <iostream>
#include <string.h>
#include "ShuntingYard.h"
using namespace std;

int main() {
    string ex = "5*(0.2) < 1";
    string e = "12*0.2 >) (2)";
    ShuntingYard s;
    cout <<s.evaluate(e)<<endl;
    return 0;
}