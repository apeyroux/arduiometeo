#!/bin/bash

find log/ -name meteo-*.log -exec cat {} \; >> log/full.log
