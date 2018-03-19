#include "write.h"

void create_out(int menor, int num_test, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_, string filename) {
    /*Output file containing all algorithms informations.*/
    ofs_.open(filename.c_str());

    /*Output file for each algorithm. Contains the data only for one algorithm.*/
    ofstream new_outfile;
    size_t dot = filename.find('.');    //Location where I shall change filename.
    string temp;                        //Name for each output file. Keeps changing it's name.

    cout << "#Size";
    ofs_ << "#Size";
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};
    for(int i=0; i<7; ++i) {
        if(bin[i] == '1') {
            temp.assign(filename);          //Restarting string 'temp' as original parameter 'filename'.
            temp.insert(dot, "_");          //Putting a '_' right before the dot in string 'filename'.(temp). 
            temp.insert(dot+1, t[i]);       //Putting Algorithm name, to differ one graphic from another. 

            new_outfile.open(temp.c_str()); //Opens output stream.
            new_outfile << "#Size";
            //ofs_.open("out/graficos.txt"); //How to change a file name, based on an variable.
            /*
            Quero criar gráfico1.txt, gráfico2.txt,...,gráfico7.txt, um pra cada algoritmo
            aí tipo, se bin[i] tiver '1'(se eu quiser usar o algortimo), então eu dou
            open() e close() dentro de cada if. Porém quero introduzir a variável 'i' 
            no nome do arquivo saída.
            */
            /*Writing the algorithms used on Terminal and outputs files.*/
            cout << setw(14) << right << t[i] << "   ";
            ofs_ << setw(14) << right << t[i] << "   ";
            new_outfile << setw(14) << right << t[i] << "   " << endl << endl;
            for(int j=0; j<=num_test; ++j) {
                new_outfile << setw(12) << left << menor+j*(MAXT-menor)/num_test;
                new_outfile << setw(14) << left << setprecision(7) << tempo[j][i].count() << "   ";
                new_outfile << endl;
            }
            new_outfile.close();        //Closes output stream.
        }
    }
    cout << endl << endl;
    ofs_ << endl << endl;
    for(int i=0; i<=num_test; ++i) {
        cout << setw(12) << left << menor+i*(MAXT-menor)/num_test;
        ofs_ << setw(12) << left << menor+i*(MAXT-menor)/num_test;
        for(int j=0; j<7; ++j) {
            if(bin[j] == '1') {
                cout << setw(14) << left << setprecision(7) << tempo[i][j].count() << "   ";
                ofs_ << setw(14) << left << setprecision(7) << tempo[i][j].count() << "   ";
            }
        }
        ofs_ << endl;
        cout << endl;
    }

    ofs_.close();
}