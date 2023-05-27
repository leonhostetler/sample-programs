#!/bin/bash

# Suppose we want to create a text file that contains only columns 2 and 3
# from the text file data.txt

# Usage: bash extract_columns_from_file.sh

input_file='data.txt'
output_file='out.txt'

cat $input_file | awk '{print $2, $3}' > $output_file





