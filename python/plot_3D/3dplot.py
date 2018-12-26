#! /usr/bin/env python
"""
3D scatter plot with z-errors

Leon Hostetler, June 9, 2018

To use:

    python 3dplot.py

"""

from __future__ import division, print_function

import sys
import numpy as np
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as axes3d

fig = plt.figure(dpi=100)
ax = fig.add_subplot(111, projection='3d')

filename = 'data.txt'

# Load the data from text file
data = np.loadtxt(filename, float)
x = data[:, 0]
y = data[:, 1]
z = data[:, 2]

#error data
zerror = data[:, 3]

#plot points
ax.plot(x, y, z, linestyle="None", marker="o")

#plot errorbars
for i in np.arange(0, len(x)):
    ax.plot([x[i], x[i]], [y[i], y[i]], [z[i]+zerror[i], z[i]-zerror[i]], marker="_")

plt.title("Plot Title")
plt.xlabel("x")
plt.ylabel("y")

plt.show()
