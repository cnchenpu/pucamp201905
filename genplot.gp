reset

set xlabel 'N'
set ylabel 'Time(sec)'
set style fill solid
set title 'compute_pi time'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_clock_gettime.csv" using 1:2 title 'Baseline' with linespoints, \
     "result_clock_gettime.csv" using 1:3 title 'Leibniz' with linespoints, \
     "result_clock_gettime.csv" using 1:4 title 'Euler' with linespoints

