#! /usr/bin/env python
"""
Generates a plot of f(x) = x^2

Leon Hostetler, June 9, 2018
"""

from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np


def fun(x):
    """ Define the function """
    return x**2

# Endpoints and resolution
start = -2.0
stop = 2.0
res = 1000

# x and y-values
x = np.linspace(start, stop, res)
y = fun(x)

# Plot the results
plt.rc('text', usetex=True)
plt.plot(x,y)
plt.legend([r"$f(x) = x^2$"])
plt.title("Plot Title")
plt.savefig("plot.png")
plt.show()
