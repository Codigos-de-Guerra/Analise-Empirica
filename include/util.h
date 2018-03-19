#ifndef UTIL_H
#define UTIL_H
/*
Util,h is our file '.h', where we store all includes
in common need for the entire program.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <cmath>
#include <ratio>
#include <stdlib.h>

//#define MAXT 4100750
//#define MAXT 75500250
using namespace std;
using Ptr_Func = long int* (*)(long int*, long int*, long int, int&);

//Function to generate my array of pointers to the search functions.
Ptr_Func* Pointer_to_Func(void);

//Function to execute the desired search algorithms and make a calculation on the time averages on milliseconds.
//Returns a pointer containing all time averages of each desired search algorithm on milliseconds.
chrono::duration<double, milli> ExecFunc(long int *first, long int *last, Ptr_Func Func, int &steps);

#endif