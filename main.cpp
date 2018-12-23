#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "FlightController.h"

using namespace std;
typedef string :: iterator stritr;

bool isD(char c) {
    return c <= '9' && c >= '0';
}

stritr findit(stritr beg, stritr end, char toFind) {
    find_if(beg + 1, end, [toFind](char c) { return c == toFind; }) + 1;
}

stritr findn(stritr beg, stritr end) {
    return find_if_not(beg, end, isD);
}

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