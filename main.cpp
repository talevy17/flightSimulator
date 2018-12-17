#include <iostream>
#include "Expression.h"
#include "ShuntingYard.h"

int main() {
    string ex = "100/2+(3*8+(5-2)-(-4))*2";
    ShuntingYard s;
    double n = s.evaluate(ex);
    cout<<n<<endl;
    return 0;
}