#! /usr/bin/env python
"""

Clean a text file containing tabular data.

Leon Hostetler, June 9, 2018

USAGE: python clean.py

"""

from __future__ import division, print_function
import numpy as np
import sys

# Filenames
inputfile  = 'inputdata.txt'
outputfile = 'outputdata.txt'

# Import the data from the file. Commented rows are not imported.
# Only import the first five columns
data = np.genfromtxt(inputfile, comments='#', usecols=(0,1,2,3,4), dtype=str)

# Clean the first two columns by replacing each 'p' with '.'
# Then recombine the columns
cleancol1 = [s.replace('p' , '.') for s in data[:,0]]
cleancol2 = [s.replace('p' , '.') for s in data[:,1]]
data1 = np.column_stack([cleancol1,cleancol2,data[:,2],data[:,3],data[:,4]])

# Remove the duplicate rows
# NOTE: This changes the order of the rows in the array
data2 = np.vstack({tuple(row) for row in data1})

# Write the first row to the output file
with open(outputfile, "w") as text_file:
   text_file.write("#col1   col2   col3   col4   col5\n")

# Append the cleaned data to the output file
f = open(outputfile, "a")
np.savetxt(f, data2, fmt='%s')
f.close()
