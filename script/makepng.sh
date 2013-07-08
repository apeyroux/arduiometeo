#!/bin/bash

dthr=$(date +"%d%m%Y-%H%M%S")

./meteo2csv.sh
gnuplot ./gnuplot/meteo.gp > ./png/meteo-$dthr.png 
rm ./png/latest.png
ln -s ~/codaz/meteostation/script/png/meteo-$dthr.png ./png/latest.png
