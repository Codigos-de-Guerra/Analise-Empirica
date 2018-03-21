#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Script para gerar graficos no GNUPLOT" << endl;
    cout << "Selecione os algoritmos que terao seus graficos gerados em conjunto" << endl;
    cout << "Selecione tambem se deseja um grafico de Tempo x Tamanho, ou Iteracoes x Tamanho" << endl;
    cout << "Exemplo de entrada:" << endl;
    cout << "  1 1111111   Exemplo em que todos os algoritmos sao selecionados e gerados em Tempo x Tamanho" << endl;
    cout << "  0 0110000   Exemplo em que apenas os algoritmos binarios sao selecionados e gerados em Iteracoes x Tamanho" << endl;

    int x;
    cin >> x;
    string s;
    cin >> s;
    cout << s;
    
  //  if(arg_ok(s) || (x != 1 && x != 0)) {
    //    cout << "f" << endl;
      //  return 0;
    //}
/*----------------------------------------------------------------------------------------*/
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
        ofs << "set ylabel 'Tempo médio de busca em segundos'" << endl;
        ofs << "set title 'Tempo médio de busca para tamanho de amostra'" << endl;
        ylabel = "_Time";                   //It is a Time type.
        file_to_plot.assign("Tempo(s)_");
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

    //for(int i=0; i<7; ++i) {
      //  if(s[i] == '1') {
        //    ofs << "plot";
          //  break;
        //}
    //}
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
    //system("\"");
}