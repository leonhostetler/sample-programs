reset

# To output image only, uncomment the following two lines
#set term pos eps color enhanced defaultplex "Helvetica" 26
#set output 'plot.eps'

# To adjust the aspect ratio uncomment and adjust the following (i.e. stretch x2 in x-direction)
#set size 2,1

set xlabel "x"
set ylabel "y"

set xrange [0:15]
set yrange [-0.5:2.5]

set title "My Plot"

plot "data.txt" using 1:2:3 notitle with error linetype 8 linewidth 2

# Can also use shorthand:
#plot "data.txt" u 1:2:3 not w e lt 8 lw 2

# Use 'pause -1' to keep the plot open long enough to see it
pause -1


