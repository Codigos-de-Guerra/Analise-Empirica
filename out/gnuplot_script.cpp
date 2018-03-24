#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Script to generate graphics on GNUPLOT." << endl;
    cout << "Select algorithms to be used on plot making together." << endl;
    cout << "Choose also if you desire a plot type of: 'Tempo x Tamanho' or 'Iteracoes x Tamanho'." << endl;
    cout << "Input example:" << endl;
    cout << " 1 1111111  Example where all algorithms are selected to plotting on type of: 'Tempo x Tamanho'." << endl;
    cout << " 0 0110000  Example where only binary searchs are generated and on type of: 'Iteracoes x Tamanho'." << endl;

    int x;
    cin >> x;
    string s;
    cin >> s;
    cout << s;
    
/*---------------------------------------------------------------------------------------------------------------------*/
    string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};                      //String to store the enshortened algorithm name.
    /* String to store the full length name of my search algorithms. */
    string T[] = {"Iterative Linear Search", "Iterative Binary Search", "Recursive Binary Search", "Iterative Ternary Search", "Recursive Ternary Search", "Fibonacci Search", "Jump Search"};

    string file_to_plot;            //String to help me make my code more dynamic on the aspect of which file is going to generate image graphic.
    string ylabel;                  //The 'y' axis of graphic.

    ofstream ofs;
    ofs.open("ploty.gnu");

    ofs << "## Type of graphic (x) -> " << x << endl;
    ofs << "## Algorithms selected (s) -> " << s << endl;
    ofs << "set terminal png size 1024,768" << endl;                    //Setting quality of image output.
    ofs << "set xlabel 'Tamanho da amostra'" << endl;                   //Setting our 'x' axis on graphic.

    if(x == 1) {
        ofs << "set ylabel 'Tempo médio de busca em microsegundos'" << endl;
        ofs << "set title 'Tempo médio de busca para tamanho de amostra'" << endl;
        ylabel = "_Time";                   //It is a Time type.
        file_to_plot.assign("Tempo(µs)_");
    }
    else  {
        ofs << "set ylabel 'Iterações executadas'" << endl;
        ofs << "set title 'Iterações executadas para cada tamanho de amostra'" << endl;
        ylabel = "_Step";                   //It is a Step type.
        file_to_plot.assign("Passos_");
    }
    ofs << "set grid" << endl;
    ofs << "set style data linespoints" << endl;
    ofs << "set key below left" << endl;
    ofs << "set output '" << s << ylabel << ".png'" << endl;    //Creating output name for my image containing graphic.

    int count = 0;              //To know if some algorithm got selected.
    for(int j=0; j<7; ++j) {
        if(s[j] == '1') {
            count++;
        }
    }

    if(count == 0) {                           //If nono got selected, then there is nothing to do.
        system("echo No graphic generated!");
        return 0;
    }

    ofs << "plot";

    for(int i=0; i<7; ++i) {
        if(s[i] == '1') {
            /* Plots graphic with lines representing choosen algorithms. */
            ofs << " '" << file_to_plot << t[i] << ".txt' with linespoints title '" << T[i] << "'";
            ofs << ",";
        }
    }

    ofs.close();
    system(" gnuplot < ploty.gnu");
}