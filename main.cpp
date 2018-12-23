#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "FlightController.h"

using namespace std;
typedef string :: iterator stritr;

<<<<<<< HEAD
bool isD(char c) {
    return c <= '9' && c >= '0';
}
=======
/*int main (){

}
    vector<string> commandLine;
    commandLine.push_back("hi");
    commandLine.push_back("hello");
    commandLine.push_back("sh");
    vector<string> :: iterator it;
    string::iterator co;
    it = commandLine.begin();
    ++it;
    string i = *it;
=======*/
#include "FlightDataVariables.h"
#include <vector>
#include "VarCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "PrintCommand.h"
#include "OpenDataServer.h"
>>>>>>> 90277479cd3fe08e0b946eccf5cc45e6bca6e9f8

stritr findit(stritr beg, stritr end, char toFind) {
    find_if(beg + 1, end, [toFind](char c) { return c == toFind; }) + 1;
}

stritr findn(stritr beg, stritr end) {
    return find_if_not(beg, end, isD);
}

<<<<<<< HEAD
stritr findE (stritr beg, stritr end){
    bool found = false;
    stritr i,j;
    while (!found){
        i = findn(beg,end);
        j = findit(i,end,'.');
        if (*j == *end ){
            found = true;
            j = i;
        }
        beg = j;
    }
    return j;
}

int main (){
    vector<string> c;
    Lexer l;
    string s = "3.454.545 , 6";
    stritr b = s.begin();
    stritr e = s.end();
    stritr f = findE(b,e);
    string d = string (b,f);
    if ((*f!=*e)){
        cout << "fail" << endl;
    }
    return 0;
}
=======
int main() {
    map<string, Command *> commands;
    FlightDataVariables data;
    data.flightDataInit();
    VarCommand v(&data);
    commands.insert(std::pair<string, Command *>("var", &v));
    IfCommand f(&data, &commands);
    commands.insert(std::pair<string, Command *>("if", &f));
    WhileCommand w(&data, &commands);
    commands.insert(std::pair<string, Command *>("while", &w));
    PrintCommand p(&data);
    commands.insert(std::pair<string, Command*>("print", &p));
    OpenDataServer ser(data);
    commands.insert((std::pair<string, Command*>("openDataServer", &ser)));
    vector<string> expression;
    expression.push_back("openDataServer");
    expression.push_back("5400");
    expression.push_back(",");
    expression.push_back("10");
    expression.push_back(";");
    expression.push_back("var");
    expression.push_back("tal");
    expression.push_back("=");
    expression.push_back("bind");
    expression.push_back("\"/engines/engine/rpm\"");
    expression.push_back(";");
    expression.push_back("print");
    expression.push_back("tal");
    expression.push_back(";");
    auto it = expression.begin();
    try {
        ser.execute(it);
        v.execute(it);
        p.execute(it);
        cout << "the first if var's name: " << data.getVar("tal")->getName() << ", the value is: " <<
             data.getVar("tal")->calculate() << endl;
    } catch (const char *e) {
        cout << e << endl;
    }
}
>>>>>>> 90277479cd3fe08e0b946eccf5cc45e6bca6e9f8
