#! /usr/bin/env python
"""
Plots an exponential Fourier series by adding the C_n coefficients and
specifying the limits. Compare against another function.

Leon Hostetler, Jun. 14, 2016

USAGE: python fourier_series_complex.py
"""
from __future__ import division, print_function
import numpy as np
import matplotlib.pyplot as plt

L = 1           # Enter the value for L here where the function is defined on [-L,L] or [0,L]
left = -2*L     # Modify these values to adjust graph domain and resolution
right = 2*L
res = 1000

# Enter the expression for the C_n coefficients
# Use 1j for the imaginary unit
# Note this program uses the complex Fourier series definition in which the
# negative exponent is in the series rather than in the integral formula for c_n
# Notice that you have to separate the c_0 definition from the other c_n since 
# it will often cause a division by zero error otherwise
def C_n(n):
    if n == 0:
        return (1/(2*L+2*1j*n*np.pi))*(np.exp(L+1j*n*np.pi)- np.exp(-L-1j*n*np.pi))
    else:
        return (1/(2*L+2*1j*n*np.pi))*(np.exp(L+1j*n*np.pi)- np.exp(-L-1j*n*np.pi))

# The number of terms for n > 0 to use in the Fourier series
# This program will calculate the same number of terms for n < 0, plus
# the n = 0 term. In other words, if you enter terms = 100, this program will 
# compute 201 terms centered at n = 0.
terms = 100     


################################
#  Compare with a single period of the actual function
################################

r = np.linspace(-L,L,res)

def fun(x):         # Define the function to compare against, here:
    return np.exp(x)

y2 = np.array([fun(i).real for i in r])


################################
#  Leave everything alone below this point
################################

x = np.linspace(left,right,res)

def f(x,limit):
    f = np.array([(C_n(n)*np.exp(-1j*n*np.pi*x/L)) for n in range(-limit,limit)])
    return f.sum()

y = np.array([f(i,terms).real for i in x])

fig, ax = plt.subplots()
ax.plot(x,y)
ax.plot(r,y2)
ax.grid()
axes = plt.gca()
axes.set_xlim([left,right])
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')
plt.show()
