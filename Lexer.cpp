#include "Lexer.h"
#include "FlightController.h"
#include <algorithm>
#include <fstream>

#define SPACE ' '
#define TAB '\t'
#define END_OF_ROW ";"
//end of parameter
#define END_OF_PRM ","

using namespace std;
typedef string::iterator stritr;

/**
 * the function gets char and checks if it between 0 to 9
 * @param c - char type
 * @return bool, true - if c is a digit, false - else
 */
bool isDigit(char c) {
    return (c <= '9' && c >= '0') || c == '.';
}

/**
 * the function gets char and checks if it a letter
 * @param c - char type
 * @return bool, true - if c is a letter, false - else
 */
bool isLetter(char c) {
    //turn each letter to small letter.
    c = (char) tolower(c);
    return c <= 'z' && c >= 'a';
}

/**
 * the function gets char and checks if its part of variable
 * if its digit, letter or bottom line
 * @param c - char type
 * @return bool, true - if c is part of var, false - else
 */
bool isVar(char c) {
    return isDigit(c) || isLetter(c) || c == '_';
}

/**
 * the function gets 2 iterators , for begin and end
 * and find the first non digit - the end of the number
 * @param beg - iterator to begin
 * @param end - iterator to end
 * @return stritr - the end of the number.
 */
stritr findNum(stritr beg, stritr end) {
    return find_if_not(beg, end, isDigit);
}

/**
 * the function gets 2 iterators , for begin and end
 * and find the quotation mark - that represent the end of the address
 * @param beg - iterator to beginc
 * @param end - iterator to end
 * @return stritr - the end of the address.
 */
stritr findAddress(stritr beg, stritr end, char toFind) {
    return find_if(beg + 1, end, [toFind](char c) { return c == toFind; }) + 1;
}

/**
 * the function gets 2 iterators , for begin and end
 * check first if its an valid input, then find the first
 * non-var char,and return it.
 * @param beg - iterator to begin
 * @param end - iterator to end
 * @return stritr - the end of the variable.
 */
stritr findVar(stritr beg, stritr end) {
    if (!isLetter(*beg) && *beg != '_') return beg;
    return find_if_not(beg + 1, end, isVar);
}

/**
 * the function gets 2 iterators , for begin and end
 * and skip spaces and tabs.
 * @param beg - iterator to begin
 * @param end - iterator to end
 * @return stritr - the end of the begin of non-space.
 */
stritr skipSpaces(stritr beg, stritr end) {
    return find_if_not(beg, end, [](char c) {
        return c == SPACE || c == TAB;
    });
}

/**
 * the function gets command and vector of strings,
 * iter the line and split each relevant parameter
 * @param string line - line of commands
 * @param commandLine - vector of strings, split by variables, numbers and marks
 */
void Lexer::splitLine(string line, vector<string> &commandLine) {
    //booleans flags for add comma between parameters.
    bool separateVar = false, var = false, f = false;
    stritr itr = line.begin();
    stritr enditr = line.end();
    while (*itr != *enditr) {
        //first, skip the unnecessary spaces
        itr = skipSpaces(itr, enditr);
        stritr curr;
        //then check the current note
        if (isDigit(*itr)) {
            curr = findNum(itr, enditr);
            if (var) { f = true; }
            var = true;
        } else if (isLetter(*itr)) {
            curr = findVar(itr, enditr);
            if (var) { f = true; }
            var = true;
            string mode = string(itr, curr);
            //if the command get multiply parameters change the separateVar flag.
            if (mode == "openDataServer" || mode == "connect" || mode == "print") {
                separateVar = true;
                var = false;
            }
        } else if (*itr == '"') {
            curr = findAddress(itr, enditr, '"');
        } else {
            curr = itr + 1;
            var = false;
        }
        if (itr >= curr) return;
        if (f && separateVar) {
            commandLine.emplace_back(END_OF_PRM);
            f = false;
        }
        //push the substring to the vector
        commandLine.emplace_back(string(itr, curr));
        //raise itr
        itr = curr;
    }
    if (commandLine.back() == "{"){
        commandLine.pop_back();
        commandLine.emplace_back(END_OF_ROW);
        commandLine.emplace_back("{");
    }
    //if the last string in the vector is "," - pop it.
    if (commandLine.back() == END_OF_PRM) {
        commandLine.pop_back();
    }
    //add ";" in the end of line command.
    commandLine.emplace_back(END_OF_ROW);
}