#!/bin/bash

# commandline.sh
#
# Leon Hostetler, June 9, 2018
#
# USAGE:   sh commandline.sh <commandline variables>
# EXAMPLE: sh commandline.sh hello 16
# EXAMPLE: sh commandline.sh 'Hello my name is Leon'
#

# Get the command line input
# Commandline variables are space-separated unless enclosed in quotes
input1=$1
input2=$2
input3=$3

echo "The zeroth commandline variable is the name of the script: " $0
echo "Your first command line variable: " $input1
echo "Your second command line variable: " $input2
echo "Your third command line variable: " $input3

# You can do stuff with these variables
# For example, create a file named with your first variable:
echo "Test File" > ${input1}.txt



