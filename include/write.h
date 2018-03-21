#ifndef WRITE_H
#define WRITE_H

#include "util.h"
/*File '.h' containing printing on output streams program codes. */
/*----------------------------------------------------------------------------------*/

/*Procedure to write steps taken inforamtion along with array size.*/
void StepFile(long int menor, long int maior, long int casos, string bin, long int **passos, ofstream& ofs_, string filename);

/*Procedure to write time information along with array size. Also prints on terminal.*/
void TimeFile(long int menor, long int maior, long int casos, string bin, chrono::duration<double> **tempo, ofstream& ofs_, string filename);

/*Procedure to prlong int onto terminal all informations obtained, in a human readable format.*/
void printTerminal(long int menor, long int maior, long int casos, string bin, chrono::duration<double> **tempo, long int **passos);

#endif