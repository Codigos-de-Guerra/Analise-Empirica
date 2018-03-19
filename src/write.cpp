#include "write.h"

void TimeFile(int menor, int maior, int casos, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, string filename, int **passos) {
    /*Output file containing information over array size and time spent on search.*/
    size_t dot = filename.find('.');
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};
    string temp;                                //String where i will store my temporaly filenames.

    for(int i=0; i<=casos; i++) {
        /*Now, I also print some of the information adquired on the terminal.*/
        cout << "Algorithm    " << "#Size      " << "Time       " << "Iterations" << endl;
        cout << setw(50) << setfill('-') << ": ";
        cout << endl;
        for(int j=0; j<7; j++) {
            if(bin[j] == '1') {
                temp.assign(filename);                  //Restarting string 'temp' as original parameter 'filename'.
                temp.insert(dot, "_");                  //Putting a '_' right before the dot in string 'filename'.(temp).
                temp.insert(dot+1, t[j]);               //Putting Algorithm name, to differ one file from another. 

                ofs_.open(temp.c_str(), ofstream::app);        //Opens output stream.
                ofs_ << menor+i*(maior-menor)/casos << " ";         //Printing on file the size of analised array.
                ofs_ << tempo[i][j].count() << endl;                //Printing on file the time spent com it's correspondent array size.

                /*Here, I print on the terminal as well.*/
                if(j==6) {
                    cout << t[j] << ":        " << menor+i*(maior-menor)/casos << "      " << tempo[i][j].count() << "ms     " << passos[i][j] << " iterations." << endl;
                    continue;
                }
                cout << t[j] << ":       " << menor+i*(maior-menor)/casos << "      " << tempo[i][j].count() << "ms       " << passos[i][j] << " iterations." << endl;
                ofs_.close();
            }
        }
        cout << endl;
    }
}

void StepFile(int menor, int maior, int casos, string bin, int **passos, ofstream& ofs_, string filename) {
    /*Outout file containing information over array size in association with steps took by the main function on determined search algorithm.*/
    size_t dot = filename.find('.');
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};
    string temp;                                //String where i will store my temporaly filenames.

    for(int j=0; j<7; j++) {
        if(bin[j] == '1') {
            temp.assign(filename);                  //Restarting string 'temp' as original parameter 'filename'.
            temp.insert(dot, "_");                  //Putting a '_' right before the dot in string 'filename'.(temp).
            temp.insert(dot+1, t[j]);               //Putting Algorithm name, to differ one file from another. 
            ofs_.open(temp.c_str(), ofstream::app);             //Opens output stream.
            for(int i=0; i<=casos; i++) {
                ofs_ << menor+i*(maior-menor)/casos << " ";         //Printing on file the size of analised array.
                ofs_ << passos[i][j] << endl;                //Printing on file the time spent com it's correspondent array size.
            }
            ofs_.close();
        }
    }
}

//void Steps_out(int menor, int num_test, string bin, ofstream& ofs_, string filename) {
    /* Output file containing number of iterations per */
//}