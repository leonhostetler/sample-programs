#!/bin/bash

# 
# run.sh                                                               
# 
# Leon Hostetler, June 9, 2018
# 
# CALL USING: sh run.sh 
# 

# Compile the C program 'helloworld'
gcc helloworld.c

# Run the program and send its output to 'output.txt'
./a.out > output.txt
