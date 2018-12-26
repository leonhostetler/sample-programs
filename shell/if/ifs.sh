#!/bin/bash

# 
# ifs.sh                                                               
# 
# Leon Hostetler, June 9, 2018
# 
# CALL USING: sh ifs.sh 
# 


# If the file does not exist, then say so
if [ ! -f file1.txt ]; then 
  echo "The file does not exist"
fi

# Can also do it on a single line if you add a semicolon
if [ ! -f file1.txt ]; then echo "The file does not exist"; fi

echo "ifs.sh: Done"
