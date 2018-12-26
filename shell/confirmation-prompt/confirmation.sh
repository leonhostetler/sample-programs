#!/bin/bash

#
# confirmation.sh
# 
# A shell script that includes a confirmation prompt
#
# USAGE: sh confirmation.sh
#

echo "What happens next will surprise you!"

read -p "Continue (y/n)?" CONT
if [ "$CONT" = "y" ]; then
    echo "Just kidding"
else
  echo "Coward!";
fi



