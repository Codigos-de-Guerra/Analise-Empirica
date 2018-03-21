#include "write.h"

void TimeFile(long int menor, long int maior, long int casos, string bin, chrono::duration<double> **tempo, ofstream& ofs_, string filename) {
    /*Output file containing information over array size and time spent on search.*/
    size_t dot = filename.find('.');
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};			//Just a reference to algorithms used.
    string temp;                                							//String where i will store my temporaly filenames.

    for(int j=0; j<7; j++) {
        if(bin[j] == '1') {
            temp.assign(filename);                  //Restarting string 'temp' as original parameter 'filename'.
            temp.insert(dot, "_");                  //Putting a '_' right before the dot in string 'filename'.(temp).
            temp.insert(dot+1, t[j]);               //Putting Algorithm name, to differ one file from another. 
            ofs_.open(temp.c_str());        		//Opens output stream.

      		for(long int i=0; i<=casos; i++) {
            	ofs_ << menor+i*(maior-menor)/casos << " ";         //Printing on file the size of analised array.
            	ofs_ << fixed << setprecision(12) << tempo[i][j].count() << endl;                //Printing on file the time spent com it's correspondent array size.l;
       		}
            ofs_.close();
    	}
    }
}

void StepFile(long int menor, long int maior, long int casos, string bin, long int **passos, ofstream& ofs_, string filename) {
    /*Outout file containing information over array size in association with steps took by the main function on determined search algorithm.*/
    size_t dot = filename.find('.');
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};			//Just a reference to algorithms used.
    string temp;                                							//String where i will store my temporaly filenames.

    for(int j=0; j<7; j++) {
        if(bin[j] == '1') {
            temp.assign(filename);                  //Restarting string 'temp' as original parameter 'filename'.
            temp.insert(dot, "_");                  //Putting a '_' right before the dot in string 'filename'.(temp).
            temp.insert(dot+1, t[j]);               //Putting Algorithm name, to differ one file from another. 
            ofs_.open(temp.c_str());             	//Opens output stream.

            for(long int i=0; i<=casos; i++) {
                ofs_ << menor+i*(maior-menor)/casos << " ";         //Printing on file the size of analised array.
                ofs_ << passos[i][j] << endl;               		//Printing on file the time spent com it's correspondent array size.
            }
            ofs_.close();
        }
    }
}

void printTerminal(long int menor,long int maior,long int casos, string bin, chrono::duration<double> **tempo, long int **passos) {
    /*Prints onto terminal all informations obtained in a human readable format.*/
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};				//Just a reference to algorithms used.

    /*Here we execute our printing*/
    for(long int i=0; i<=casos; i++) {
        cout << "Algorithm " << i << "   #Size      " << "Time       " << "Iterations" << endl;
        cout << setw(50) << setfill('-') << ": ";
        cout << endl;
      	for(int j=0; j<7; j++) {
        	if(bin[j] == '1') {
            	if(j==6) {				//Just a fix for organization of information displayed onto terminal.
                	cout << t[j] << ":        " << menor+i*(maior-menor)/casos << "      " << tempo[i][j].count() << "s     " << passos[i][j] << " iterations." << endl;
                	continue;
            	}
            cout << t[j] << ":       " << menor+i*(maior-menor)/casos << "      "<< fixed << setprecision(12) << tempo[i][j].count() << "s       " << passos[i][j] << " iterations." << endl;
       		}
    	}
        cout << endl;
    }
}