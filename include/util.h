#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <random>
#include <math.h>
#define MAXT 10000
//#define MAXT 4090750
using namespace std;
//using long int*(**)(long int*, long int*, long int) lili;

//Function to generate my array of pointers to the search functions.
long int* (**Pointer_to_Func(void))(long int*, long int*, long int);
void ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int));

#endif
