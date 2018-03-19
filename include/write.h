#ifndef WRITE_H
#define WRITE_H

#include "util.h"
/*
Procedure to output chart containing times and Algorithms
used for each different array on the terminal, on a general file with
all information and 'n'(as an integer) differents files each 
with a different Search Algorithm.
*/
void create_out(int menor, int num_test, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, string filename);

#endif