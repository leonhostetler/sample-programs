#! /usr/bin/env python
"""
Plot from a file.

Leon Hostetler, June 9, 2018
"""

from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np


# Import the plot data from the file
data = np.genfromtxt('data.txt')

# Number of data points in file
ndata = data.shape[0]
x = data[:,0]
y = data[:,1]
e = data[:,2]

# Plot the results
plt.title("Plot Title")
plt.scatter(x, y)
plt.errorbar(x, y, yerr=e, linestyle='None', capsize=3)
plt.savefig("plot.png")
plt.show()
