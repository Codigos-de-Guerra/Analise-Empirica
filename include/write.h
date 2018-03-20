#ifndef WRITE_H
#define WRITE_H

#include "util.h"
/*File '.h' containing printing on output streams program codes. */
/*----------------------------------------------------------------------------------*/

/*Procedure to write steps taken inforamtion along with array size.*/
void StepFile(int menor, int maior, int casos, string bin, int **passos, ofstream& ofs_, string filename);

/*Procedure to write time information along with array size. Also prints on terminal.*/
void TimeFile(int menor, int maior, int casos, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, string filename);

/*Procedure to print onto terminal all informations obtained, in a human readable format.*/
void printTerminal(int menor, int maior, int casos, string bin, chrono::duration<double, milli> **tempo, int **passos);

#endif