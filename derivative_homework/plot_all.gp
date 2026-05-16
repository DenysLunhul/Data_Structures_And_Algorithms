set terminal pngcairo size 1200,800 enhanced font 'Arial,13'
set grid lw 1 lc rgb '#cccccc'
set border lw 1.5
set xlabel 'x' font 'Arial,13'
set ylabel 'y' font 'Arial,13'
set key top left font 'Arial,12'
set style line 1 lc rgb '#0060ad' lw 2.5
set style line 2 lc rgb '#dd181f' lw 2.5 dt 2
set output 'sin_plot.png'
set title 'sin(x) and its derivative' font 'Arial,15'
set xrange [-6.28319:6.28319]
set autoscale y
plot 'sin_data.dat' using 1:2 with lines ls 1 title 'sin(x)', 'sin_data.dat' using 1:3 with lines ls 2 title "f'(x) (derivative)"
set output 'exp_plot.png'
set title 'exp(x) and its derivative' font 'Arial,15'
set xrange [-3:3]
set autoscale y
plot 'exp_data.dat' using 1:2 with lines ls 1 title 'exp(x)', 'exp_data.dat' using 1:3 with lines ls 2 title "f'(x) (derivative)"
set output 'pow3_plot.png'
set title 'x^3 and its derivative' font 'Arial,15'
set xrange [-5:5]
set autoscale y
plot 'pow3_data.dat' using 1:2 with lines ls 1 title 'x^3', 'pow3_data.dat' using 1:3 with lines ls 2 title "f'(x) (derivative)"
set output 'sqrt_plot.png'
set title 'sqrt(x) and its derivative' font 'Arial,15'
set xrange [0.01:10]
set autoscale y
plot 'sqrt_data.dat' using 1:2 with lines ls 1 title 'sqrt(x)', 'sqrt_data.dat' using 1:3 with lines ls 2 title "f'(x) (derivative)"
