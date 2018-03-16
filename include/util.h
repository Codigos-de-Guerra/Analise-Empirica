#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <math.h>
#define MAXT 1000000
//#define MAXT 40740500
using namespace std;
//using long int*(**)(long int*, long int*, long int) lili;

//Function to generate my array of pointers to the search functions.
long int* (**Pointer_to_Func(void))(long int*, long int*, long int);

//Function to execute the desired search algorithms and make a calculation on the time averages.
//Returns a pointer containing all time averages of each desired search algorithm.
chrono::duration<double>* ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int));

#endif
