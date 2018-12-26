reset
set title "Plot Title"
set key bottom right
set xlabel "x"
set ylabel "y"

# Note: Uses columns 4,5,6 from the text files

plot 'data1.txt' u 4:5:6 title "Data 1" with e lt 1,\
     'data2.txt' u 4:5:6 title "Data 2" with e lt 4,\
     'data3.txt' u 4:5:6 title "Data 3" with e lt 5,\
     'data4.txt' u 4:5:6 title "Data 4" with e lt 6
pause -1
