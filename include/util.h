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
#define MAXT 4090750
using namespace std;

//Function to generate my array of pointers to the search functions.
long int* (**Pointer_to_Func(void))(long int*, long int*, long int);
//void create_vet(vector<long int> &vet, long int tam);

#endif
