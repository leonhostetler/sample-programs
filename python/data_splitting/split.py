#! /usr/bin/env python
"""

Split a text file into two based on the two possible values in the first column.

Leon Hostetler, June 9, 2018

USAGE: python split.py

"""

from __future__ import division, print_function
import numpy as np
import sys

# Filenames
inputfile  = 'inputdata.txt'

# Import the data from the file. Commented rows are not imported.
data = np.genfromtxt(inputfile, comments='#', dtype=str)

# Sort the data by the first column
data = data[data[:,0].argsort()]

# Number of rows to include in first output file
numrows = 0
for i in range(data.shape[0]):
   if data[i,0] == '2.30':
      numrows += 1

# Write the first row to the output files
with open('output1.txt', "w") as text_file:
   text_file.write("#col1   col2   col3   col4   col5\n")
with open('output2.txt', "w") as text_file:
   text_file.write("#col1   col2   col3   col4   col5\n")

# Append the sorted data to the output files
f = open('output1.txt', "a")
np.savetxt(f, data[0:numrows,:], fmt='%s')
f.close()

f = open('output2.txt', "a")
np.savetxt(f, data[numrows:,:], fmt='%s')
f.close()
