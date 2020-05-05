#! /usr/bin/env python
"""
After solving the partial differential heat equation of the form
u_t = ku_xx for a 1-dimensional bar or wire, the solution will be an infinite series that looks like a Fourier series, but with exponential decay term added. Once you have the solution, plug
the details in here and run the program to see the temperature profile change over time.

Leon Hostetler, Jun. 5, 2016

USAGE: python heat_equation_1d.py
"""
from __future__ import division, print_function
import numpy as np
import matplotlib.pyplot as plt

L = 1           # Enter the value for L here where the function is defined on [-L,L]
left = 0        # x location of the left end of the bar
right = L       # x location of the right end of the bar
res = 100       # Enter the desired graphing resolution (i.e. number of samplings)
terms = 30      # The number of terms to use in the Fourier series
k = 1           # Constant from the heat equation
A_0 = 0         # Enter A_0 from the solution

def A_n(n):     # Enter the expression for the A_n coefficients
    return 0

def B_n(n):     # Enter the expression for B_n coefficients
    return (4/np.pi**3)*((1-(-1)**n)/n**3)


################################
#  Leave everything alone below this point
################################

x = np.linspace(left,right,res)

# Evaluates the series solution for all x-values in linspace above and sums them, t is fixed
def f(x,t,limit):
    f = np.array([(A_n(n)*np.cos(n*np.pi*x/L)*np.exp(1)**(-k*n*np.pi*t/L)+ B_n(n)*np.sin(n*np.pi*x/L)*np.exp(1)**(-k*n*np.pi*t/L)) for n in range(1,limit + 1)])
    return f.sum()

#plt.ion()
fig, ax = plt.subplots()
ax.grid()
axes = plt.gca()
axes.set_xlim([left,right])
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')

# Next part of the code loops through the different times starting at t = 0
for t in np.arange(0,4,0.05):   # np.arange(start, stop, step)
    del ax.lines[1]             # Delete previously plotted curve
    y = np.array([f(i,t,terms).real for i in x])
    ax.plot(x,y + A_0)
    plt.pause(0.03)             # Adjust time delay here

