## Type of graphic (x) -> 1
## Algorithms selected (s) -> 0110000
set terminal png size 1024,768
set xlabel 'Tamanho da amostra'
set ylabel 'Tempo médio de busca em segundos'
set title 'Tempo médio de busca para tamanho de amostra'
set grid
set style data linespoints
set key below left
set output '0110000_Time.png'
plot 'Tempo(s)_IBS.txt' with linespoints title 'Iterative Binary Search', 'Tempo(s)_RBS.txt' with linespoints title 'Recursive Binary Search',