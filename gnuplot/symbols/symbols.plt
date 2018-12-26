reset

# Note superscripts and subscripts
set xlabel "z^2"
set ylabel "m_W(z^2)"

# Note use of Greek symbols
set title "{/Symbol b}=2.30 and {/Symbol k}=0.401"

plot "data.txt" u 1:2:3 notitle w e lt 8 lw 2
pause -1
