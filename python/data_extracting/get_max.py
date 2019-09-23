#! /usr/bin/env python
"""

Get the maximum value in a given column of a textfile containing tabular data.

Leon Hostetler, Sep. 22, 2019

USAGE: python get_max.py datafile.txt

"""

#from __future__ import division, print_function
import numpy as np
import sys

# Get data input filename from command line
inputfile = str(sys.argv[1])

# Import the data from the file. Commented rows are not imported.
data = np.genfromtxt(inputfile, comments='#', usecols=(0,1,2,3), dtype=float)

# Get the index of the maximum value in the fourth column
maxi = np.amax(data[:,3])
for i in range(len(data[:,3])):
    if data[i,3] == maxi:
        ind = i
        break

# Print that row of the text file in the order
# Col1 Col2 Col4 Col3
print("%7d %7d %3.2f %4d" %(data[ind,0],data[ind,1],data[ind,3],data[ind,2]))





