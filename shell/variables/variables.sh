#!/bin/bash

# 
# variables.sh                                                               
# 
# Leon Hostetler, June 9, 2018
#  
# CALL USING: sh variables.sh 
# 

# Create two variables
myvar1=19
myvar2="Leon Hostetler"

# Print them to the screen
echo $myvar1
echo $myvar2

# You can also run commands and assign the output to variables
# For example, here I use the command 'ls | wc -l' to count the number of files in the current directory.
numfiles=$(ls | wc -l)
echo "Number of files = " $numfiles

# Can also do arithmetic with variables (use double parentheses)
four=4
foursquared=$(($four*$four))
echo "four squared = " $foursquared
