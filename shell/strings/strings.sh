#!/bin/bash

# strings.sh
#
# Leon Hostetler, June 9, 2018
#
# USAGE:   sh strings.sh
#

# Create a variable and assign it a string
string="Hello my name is Leon"

# Print the string
echo $string

# Print everything before the 'm'
echo ${string%m*}



