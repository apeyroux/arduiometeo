#!/bin/bash

dthr=$(date +"%d%m%Y-%H%M%S")

~/codaz/meteostation/script/meteo2csv.sh
gnuplot ~/codaz/meteostation/script/gnuplot/meteo.gp > ~/codaz/meteostation/script/png/meteo-$dthr.png 
rm ~/codaz/meteostation/script/png/latest.png
ln -s ~/codaz/meteostation/script/png/meteo-$dthr.png ~/codaz/meteostation/script/png/latest.png
