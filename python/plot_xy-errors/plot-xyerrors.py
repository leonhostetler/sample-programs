#! /usr/bin/env python
"""

Plot from file with x and y error bars

Leon Hostetler, June 9, 2018

"""

from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np
import scipy.optimize as sciop
import sys

# Get the input text files
inputfile = 'data.txt'

# Import the plot data from the file
data = np.genfromtxt(inputfile, comments='#', usecols=(2,3,8,9))

print('\nPlotting data:')
print(data)

# x, y, and errors
x  = data[:,2]
xe = data[:,3]
y  = data[:,0]
ye = data[:,1]


# Plot the results
plt.errorbar(x, y, xerr=xe, yerr=ye, ls='none')
plt.show()
