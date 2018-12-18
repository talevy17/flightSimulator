#include <iostream>
#include <string.h>
#include "ShuntingYard.h"
using namespace std;

int main() {
    string ex = "5*0.2";
    ShuntingYard s;
    cout <<s.evaluate(ex)<<endl;
    return 0;
}