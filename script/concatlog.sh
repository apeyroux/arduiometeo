#!/bin/bash

find log/ -name *.log -exec cat {} \; >> log/full.txt
