#!/bin/bash

# 
# sed.sh                                                               
# 
# Leon Hostetler, June 9, 2018
# 
# CALL USING: sh sed.sh 
# 


# Delete the third line in data.txt to create the new file data1.txt
sed '3d' data.txt > data1.txt

# Insert a line at position 4
# Use the -i option to edit the file in place. I.e. a new file is not created as above
sed -i '4iThis line was inserted' data1.txt

# Replace line 8 with a line containing a few numbers separated by tabs
# Leading spaces are not printed unless preceded by the escape character '\'
sed -i '8d' data1.txt
sed -i '8i \ 64\t  65\t  66' data1.txt
