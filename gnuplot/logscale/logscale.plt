reset

set title "A plot with logscale y-axis"
set xlabel "x"
set ylabel "y"

set logscale y
set format y "10^{%L}"

plot "plot.txt" u 1:2:3 not w e lt 1 lw 2
pause -1
