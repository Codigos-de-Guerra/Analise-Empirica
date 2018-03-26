#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]) {
/*-----------------------------------------------------------------------------*/
    /*             Script to generate graphics on GNUPLOT.                 */


    istringstream ss(argv[1]);           //Minimun space alocated my array may have.
    int x;                      //Minimum array size.
    if (!(ss >> x) || (x != 1 && x != 0)) {                //Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[1] << endl;
        return -1;
    }

    istringstream zs(argv[2]);      //Binary representing the Search algorithms wished to use.
    string bin;                     //Pass this value as a string to 'bin'.
    zs >> bin;                      //Through string stream, receives the second value on command line.
    if(bin.size() != 7) {           //As I have 7 Search Algorithms.
        cerr << "Invalid number " << argv[2] << ". Must have width 7!" << endl;
        return -2;
    }

    int count = 0;              //To know if some algorithm got selected.
    for(int j=0; j<7; ++j) {        //Checks if string('number') inputted, is formated only by '1's or '0's.
        if(bin[j] != '1' && bin[j] != '0') {
            cerr << "Invalid number " << argv[2] << ". Must be in Binary form!" << endl;
            return -3;
        }
        count++;
    }

    if(count == 0) {                           //If none got selected, then there is nothing to do.
        system("echo No graphic generated!");
        return 0;
    }
    
/*---------------------------------------------------------------------------------------------------------------------*/
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};                      //String to store the enshortened algorithm name.
    /* String to store the full length name of my search algorithms. */
    string T[] = {"Iterative Linear Search", "Iterative Binary Search", "Recursive Binary Search", "Iterative Ternary Search", "Recursive Ternary Search", "Fibonacci Search", "Jump Search"};

    string file_to_plot;            //String to help me make my code more dynamic on the aspect of which file is going to generate image graphic.
    string ylabel;                  //The 'y' axis of graphic.

    ofstream ofs;
    ofs.open("out/ploty.gnu");

    ofs << "## Type of graphic (x) -> " << x << endl;
    ofs << "## Algorithms selected (bin) -> " << bin << endl;
    ofs << "set terminal png size 1024,768" << endl;                    //Setting quality of image output.
    ofs << "set xlabel 'Tamanho da amostra'" << endl;                   //Setting our 'x' axis on graphic.

    if(x == 1) {
        ofs << "set ylabel 'Tempo em microsegundos(10e-6 s)'" << endl;
        ofs << "set title 'Tempo médio de busca para tamanho de amostra'" << endl;
        ylabel = "_Time";                   //It is a Time type.
        file_to_plot.assign("out/Tempo(µs)_");
    }
    else  {
        ofs << "set ylabel 'Iterações realizadas'" << endl;
        ofs << "set title 'Iterações realizadas para cada tamanho de amostra'" << endl;
        ylabel = "_Step";                   //It is a Step type.
        file_to_plot.assign("out/Passos_");
    }
    ofs << "set grid" << endl;
    ofs << "set style data linespoints" << endl;
    ofs << "set key below left" << endl;
    ofs << "set output 'out/" << bin << ylabel << ".png'" << endl;    //Creating output name for my image containing graphic.


    ofs << "plot";

    for(int i=0; i<7; ++i) {
        if(bin[i] == '1') {
            /* Plots graphic with lines representing choosen algorithms. */
            ofs << " '" << file_to_plot << t[i] << ".txt' with linespoints title '" << T[i] << "'";
            ofs << ",";
        }
    }

    ofs.close();
    system("gnuplot < out/ploty.gnu");
}