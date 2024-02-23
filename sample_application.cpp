/* This file shall invoke the getTime() function and print the output */
#include <iostream>
#include "time_manager.h"
//#include "/home/ee212766/Documents/time_manager/lib/src/time_manager_lib.cpp"
int main() {
     int64_t epoch_time1=getTime();
     std::cout<<"Epoch time formate:"<<epoch_time1<<std::endl;
     return 0;
}
