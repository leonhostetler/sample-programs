#! /usr/bin/env python
"""
Illustrates the map input -> output for a complex function.

Leon Hostetler, Jul. 18, 2016

USAGE: python complex_mapping.py
"""
from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np

res = 100000      # Set the plot resolution

# The domain/input of the function, in this case a circle of radius r
# In other words, this defines the z-plane
r = .0015
D = r*np.cos(np.linspace(0,2*np.pi,res)) + r*1j*np.sin(np.linspace(0,2*np.pi,res))

'''
Here are a few other possible domains
D = np.linspace(-10,10,100) + 1j*5    # Horizontal line
D = 5 + 1j*np.linspace(-10,10)    # Vertical line
D = np.linspace(-5,5) + 1j*np.linspace(-5,5)    # Diagonal line
'''

# The range/output of the function
# This defines the w-plane
R = np.array([np.sin(1/i) for i in D])

# Plotting Code
fig = plt.figure()
ax1 = fig.add_subplot(121,aspect='equal')
ax1.plot(D.real,D.imag,label='z-plane')
ax2 = fig.add_subplot(122,aspect='equal')
ax2.plot(R.real,R.imag,label='w-plane')
plt.show()
