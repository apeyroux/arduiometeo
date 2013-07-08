#!/bin/bash

data=$(curl "http://10.73.0.100:8080/")
dthr=$(date +"%d%m%y-%H%M%S")
log="/home/ja/codaz/meteostation/script/log/meteo-$(date +"%d%m%y").log"

echo "$dthr;$data" >> $log
