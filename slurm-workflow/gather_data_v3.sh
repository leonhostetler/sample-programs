#!/bin/bash

# Leon Hostetler, Nov. 26, 2019

# After doing all the HPCC data runs, run this script
# to gather the data and prepare it for plotting

# From which directory?
dir="output_v3"
out_file="data_v3.txt"

# Gather all the data into files
echo "#Data for N=100M:" > $out_file
echo "#p    gen      sam      bin      dist     sort     gath     total" >> $out_file

for file in $dir/*_100M_*_.dat
do
    p="$(cut -d'_' -f3 <<<$file)"

    gen="$(awk '{if(NR==8) print $4}' $file)"
    sam="$(awk '{if(NR==9) print $4}' $file)"
    bin="$(awk '{if(NR==10) print $4}' $file)"
    dis="$(awk '{if(NR==11) print $4}' $file)"
    sor="$(awk '{if(NR==12) print $5}' $file)"
    gat="$(awk '{if(NR==13) print $4}' $file)"
    tot="$(awk '{if(NR==14) print $3}' $file)"

    echo "$p $gen $sam $bin $dis $sor $gat $tot" >> $out_file

done

echo "#" >> $out_file
echo "#Data for N=500M:" >> $out_file
echo "#p    gen      sam      bin      dist     sort     gath     total" >> $out_file

for file in $dir/*_500M_*_.dat
do
    p="$(cut -d'_' -f3 <<<$file)"

    gen="$(awk '{if(NR==8) print $4}' $file)"
    sam="$(awk '{if(NR==9) print $4}' $file)"
    bin="$(awk '{if(NR==10) print $4}' $file)"
    dis="$(awk '{if(NR==11) print $4}' $file)"
    sor="$(awk '{if(NR==12) print $5}' $file)"
    gat="$(awk '{if(NR==13) print $4}' $file)"
    tot="$(awk '{if(NR==14) print $3}' $file)"

    echo "$p $gen $sam $bin $dis $sor $gat $tot" >> $out_file

done

echo "#" >> $out_file
echo "#Data for N=2B:" >> $out_file
echo "#p    gen      sam      bin      dist     sort     gath     total" >> $out_file

for file in $dir/*_2B_*_.dat
do
    p="$(cut -d'_' -f3 <<<$file)"

    gen="$(awk '{if(NR==8) print $4}' $file)"
    sam="$(awk '{if(NR==9) print $4}' $file)"
    bin="$(awk '{if(NR==10) print $4}' $file)"
    dis="$(awk '{if(NR==11) print $4}' $file)"
    sor="$(awk '{if(NR==12) print $5}' $file)"
    gat="$(awk '{if(NR==13) print $4}' $file)"
    tot="$(awk '{if(NR==14) print $3}' $file)"

    echo "$p $gen $sam $bin $dis $sor $gat $tot" >> $out_file

done

