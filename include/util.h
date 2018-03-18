#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <cmath>
#include <ratio>
//#define MAXT 4100750
#define MAXT 75500250
using namespace std;
//using long int* (**)(long int*, long int*, long int) lili;

//Function to generate my array of pointers to the search functions.
long int* (**Pointer_to_Func(void))(long int*, long int*, long int);

//Function to execute the desired search algorithms and make a calculation on the time averages on milliseconds.
//Returns a pointer containing all time averages of each desired search algorithm on milliseconds.
chrono::duration<double, milli>* ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int));

#endif