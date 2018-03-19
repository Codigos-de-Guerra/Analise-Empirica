#ifndef WRITE_H
#define WRITE_H

#include "util.h"
/*
File '.h' containing printing on output streams program codes.
*/
//void create_out(int menor, int maior, int num_test, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, int **steps, string filename);

/*Procedure to write steps taken inforamtion along with array size.*/
void StepFile(int menor, int maior, int casos, string bin, int **passos, ofstream& ofs_, string filename);

/*Procedure to write time information along with array size. Also prints on terminal.*/
void TimeFile(int menor, int maior, int casos, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, string filename, int **passos);

#endif