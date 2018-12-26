#! /usr/bin/env python
"""

Sort a text file containing rows of tabular data by the first column.

Leon Hostetler, June 9, 2018

USAGE: python sort.py

"""

from __future__ import division, print_function
import numpy as np
import sys

# Filenames
inputfile  = 'inputdata.txt'
outputfile = 'outputdata.txt'

# Import the data from the file. Commented rows are not imported.
data = np.genfromtxt(inputfile, comments='#', dtype=str)

# Sort the data by the first column
data = data[data[:,0].argsort()]

# Write the first row to the output file
with open(outputfile, "w") as text_file:
   text_file.write("#col1   col2   col3   col4   col5\n")

# Append the cleaned data to the output file
f = open(outputfile, "a")
np.savetxt(f, data, fmt='%s')
f.close()
