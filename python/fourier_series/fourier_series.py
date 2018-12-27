#! /usr/bin/env python
"""
Plots a sin/cos Fourier series by adding the A_n and B_n coefficients and
specifying the limits. Compare against another function.

Leon Hostetler, Jun. 4, 2016

USAGE: python fourier_series.py
"""
from __future__ import division, print_function
import numpy as np
import matplotlib.pyplot as plt

L = 1           # Enter the value for L here where the function is defined on [-L,L] or [0,L]
left = -2*L     # Modify these values to adjust graph domain and resolution
right = 2*L
res = 1000
A_0 = 0         # Enter the value for A_0

def A_n(n):     # Enter the expression for the A_n coefficients
    return 0

def B_n(n):     # Enter the expression for B_n coefficients
    return (4*L**2)/(n**3*np.pi**3)*(1-(-1)**n)
    
terms = 50      # The number of terms to use in the Fourier series


################################
#  Compare with a single period of the actual function
################################

r = np.linspace(-L-.5,L+.5,res)

def fun(x):         # Define the function to compare against, here:
    return x*(L-x)

y2 = np.array([fun(i) for i in r])


################################
#  Leave everything alone below this point
################################

x = np.linspace(left,right,res)

def f(x,limit):
    f = np.array([(A_n(n)*np.cos(n*np.pi*x/L)+ B_n(n)*np.sin(n*np.pi*x/L)) for n in range(1,limit + 1)])
    return f.sum()

y = np.array([f(i,terms) for i in x])

fig, ax = plt.subplots()
ax.plot(x,y + A_0)
ax.plot(r,y2)
ax.grid()
axes = plt.gca()
axes.set_xlim([left,right])
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')
plt.show()
