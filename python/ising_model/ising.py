#! /usr/bin/env python
"""
Ising Model



"""

from __future__ import division, print_function
import numpy as np
import random as rand
import pylab as plt


def deltaU(i, j):
    "Compute the change in potential energy of the configuration."
    if i == 0:
        top = s[size-1,j]
    else:
        top = s[i-1,j]

    if i == size-1:
        bottom = s[0,j]
    else:
        bottom = s[i+1,j]

    if j == 0:
        left = s[i, size-1]
    else:
        left = s[i,j-1]

    if j == size-1:
        right = s[i,0]
    else:
        right = s[i,j+1]

    Ediff = 2*s[i,j]*(top+bottom+left+right)

    return Ediff

def initialize():
    "Initialize the array by randomly selecting 1 or -1"
    for i in range(size):
        for j in range(size):
            if rand.random() < 0.5:
                s[i,j] = 1
            else:
                s[i,j] = -1


#
# MAIN
#


size = 100  # Width of the square lattice
T = 0.001  # Temperature in units of epsilon/k

upperLimit = 100*size*size

s = np.zeros((size, size), dtype=int)  # Create the 2D array
initialize()  # Initialize the array

# Initialize the plot
#plt.ion()   # Use ion instead of figure if you want real-time updating (very slow)
plt.figure()


for iteration in range(1, upperLimit):
    i = rand.randint(0, size-1)  # Choose a random row number
    j = rand.randint(0, size-1)  # Choose a random column number
    Ediff = deltaU(i, j)    # Compute the change in potential energy of a hypothetical flip
    if Ediff <= 0:
        s[i,j] = -s[i,j]
    else:
        if rand.random() < np.exp(-Ediff/T):
            s[i,j] = -s[i,j]

    if iteration % 100000 == 0:
        print((iteration/upperLimit)*100, "% done")


# Plot the final configuration
plt.imshow(s, interpolation='nearest')
plt.show()
