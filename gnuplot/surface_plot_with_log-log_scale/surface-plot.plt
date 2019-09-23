#set key off
set logscale xy

set xlabel "N"
set ylabel "M"
#set style data lines
#set title "Maximum Speedup for N x M Matrix"
set title "Optimal Blocking Parameter, B, for N x M Matrix"

#splot 'points.txt' using 1:2:3 notitle with points palette pointsize 0.5 pointtype 7
splot 'points.txt' using 1:2:4 notitle with points palette pointsize 0.5 pointtype 7
pause -1
