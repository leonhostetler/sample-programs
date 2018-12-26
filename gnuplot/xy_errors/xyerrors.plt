reset

set title "Plot with x and y Error Bars"
#set key bottom right
#set xrange [0.2:1.1]
#set yrange [0.4:2.4]
plot 'data.txt' u 3:9:4:10 not w xyerrorbars lt 1
pause -1
