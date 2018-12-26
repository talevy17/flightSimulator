#include "SafeExit.h"

SafeExit::SafeExit(bool &exit) {
    this->exit = exit;
}

void SafeExit :: execute(vector<string>:: iterator& it){
    this->exit = true;
}