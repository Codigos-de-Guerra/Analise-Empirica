#include <iostream>
#include <string>
using namespace std;

bool arg_ok(string s){
    if(s.size() != 7) {
        return false;
    }

    for(int i = 0; i < 7; i++) {
        if(s[i] != '1' && s[i] != '0') {
            return false;
        }
    }

    return true;
}
int main() {
    cout << "Scrip para gerar graficos no GNUPLOT" << endl;
    cout << "Selecione os algoritmos que terao seus graficos gerados em conjunto" << endl;
    cout << "Exemplo de entrada:\n";
    cout << "\t\'1111111\'\tExemplo em que todos os algoritmos sao selecionados" << endl;
    cout << "\t\'0000000\'\tExemplo em que nenhum algoritmo eh selecionado" << endl;

    string s;
    cin >> s;
    cout << "meucu";
    
    if(arg_ok(s)) {
        return 0;
    }

    system("gnuplot ");
    system("set terminal png size 1024,768");

    system("set ylabel 'Tempo decorrido em milisegundos'");
    system("set xlabel 'Tamanho da amostra");

    system("set title 'Media de tempo decorrido para cada tamanho de amostra'");

    system("set grid");
    system("set style data linespoints");

    string temp = "set output ";
    // + s + "\'.png";
    temp.append(s);
    temp.append(".png");
    system(temp.c_str());

    //system("plot ");
    bool flag = false;

    if(s[0] == '1') {
        system("plot 'Tempo(ms)_ILS.txt' using 1:2 title 'Iterative Linear Search'");
    }
    if(s[1] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_IBS.txt' using 1:3 title 'Iterative Binary Search'");
    }
    if(s[2] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_RBS.txt' using 1:4 title 'Recursive Binary Search'");
    }
    if(s[3] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_ITS.txt' using 1:5 title 'Iterative Ternary Search'");
    }
    if(s[4] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_RTS.txt' using 1:6 title 'Recursive Ternary Search'");
    }
    if(s[5] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_FBS.txt' using 1:7 title 'Fibonacci Search'");
    }
    if(s[6] == '1') {
        if(!flag) system(",");
        system("plot 'Tempo(ms)_JS.txt' using 1:8 title 'Jump Search'");
    }

    system("\"");
}