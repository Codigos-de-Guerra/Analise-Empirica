set terminal png size 1920,1080;
set ylabel 'Tempo decorrido em segundos';
set xlabel 'Tamanho da amostra';

##set title 'Media de tempo decorrido para cada tamanho de amostra';

set grid;
set style data linespoints;

set title 'Grafico EDB';
set key below left;

set output 'JS.png';
plot 'Tempo(s)_JS.txt' with lines title 'JS', 'Tempo(s)_RTS.txt' with lines title 'RTS';
