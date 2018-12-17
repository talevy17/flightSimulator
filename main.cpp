#include <iostream>
#include "Expression.h"
#include "ShuntingYard.h"

int main() {
    string ex = "(4+(4-2))";
    ShuntingYard s;
    double n = s.evaluate(ex);
    cout<<n<<endl;
    return 0;
}