#! /usr/bin/env python

"""
Plots values from a text file as a histogram.

Leon Hostetler, May 25, 2018
"""

import numpy as np
import matplotlib.pyplot as plt

# Load the data from the file
data = np.loadtxt("data.txt", float)
actions = data[:, 1]

# Histogram the results
plt.hist(actions, bins='auto')
plt.title("Histogram")
plt.show()










