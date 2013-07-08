#!/bin/bash 

path_log="/home/ja/codaz/meteostation/script/log/meteo-$(date +"%d%m%y").log"
path_csv="/home/ja/codaz/meteostation/script/csv/meteo.csv"

cat $path_log | sed s/\'//g | sed s/';'/','/g | sed s/\{//g | sed s/temp://g | sed s/hum://g | sed s/\}//g > $path_csv
