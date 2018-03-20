set terminal png size 1024,768;
set ylabel 'Tempo decorrido em segundos';
set xlabel 'Tamanho da amostra';

set title 'Media de tempo decorrido para cada tamanho de amostra';

set grid;
set style data linespoints;

set title 'Grafico EDB';
set key below left;
set yrange[0:5];

set output 'FBS.png';
plot 'Tempo(s)_FBS.txt' with lines title 'FBS';