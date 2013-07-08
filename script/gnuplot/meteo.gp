#!/usr/bin/gnuplot

reset
set terminal png

set xdata time
set timefmt "%d%m%y-%H%M%S"
set format x "%d/%m\n%H:%M"

set xlabel "Date (day/month H:M)"
set ylabel "Temp/Hum"
set datafile separator ","

set title "Météo de Bessans 73480"
set key below
set grid

plot "/home/ja/codaz/meteostation/script/csv/meteo.csv" using 1:2 title "temp" with lines, "/home/ja/codaz/meteostation/script/csv/meteo.csv" using 1:3 title "hum" with lines
