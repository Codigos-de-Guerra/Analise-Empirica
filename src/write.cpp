#include "write.h"

void create_out(int menor, int num_test, string bin, chrono::duration<double, milli> **tempo, ofstream& ofs_) {
    system("mkdir -p out");
    //ofs_.open("out/graficos.txt");

    //cout << "#Size";
    //ofs_ << "#Size";
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};
    for(int i=0; i<7; ++i) {
        if(bin[i] == '1') {
            ofs_.open("out/graficos.txt"); //How to change a file name, based on an variable
            /*
            Quero criar gráfico1.txt, gráfico2.txt,...,gráfico7.txt, um pra cada algoritmo
            aí tipo, se bin[i] tiver '1'(se eu quiser usar o algortimo), então eu dou
            open() e close() dentro de cada if. Porém quero introduzir a variável 'i' 
            no nome do arquivo saída.
            */
            cout << setw(14) << right << t[i] << "   ";
            ofs_ << setw(14) << right << t[i] << "   ";
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
}