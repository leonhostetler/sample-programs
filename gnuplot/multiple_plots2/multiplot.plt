reset
set multiplot layout 1, 2 ;

set title "First Plot";
plot "plot1.txt" u 1:2:3 t "" w e lt 6 lw 1,\
     "plot1.txt" u 1:2 not w l lt 7 lw 1

set title "Second Plot";
plot "plot2.txt" u 1:2:3 t "" w e lt 6 lw 1,\
     "plot2.txt" u 1:2 not w l lt 7 lw 1

unset multiplot
pause -1



