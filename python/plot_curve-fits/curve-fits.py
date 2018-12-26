#! /usr/bin/env python
"""

Plots data from file and tries two curve fits.

Leon Hostetler, June 9, 2018

"""

from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np
import scipy.optimize as sciop

# Define the curve fit functions for plotting
def fit1(t, a, b):
    return a*t**b

def fit2(t, a, b, c):
    return a + b*t**c


# Input text file
inputfile = 'data.txt'

# Import the plot data from the file specified in shell script
data = np.genfromtxt(inputfile, comments='#')

# x, y, and error bar of data to be fitted
x = data[:,0]
y = data[:,1]
e = data[:,2]

#########################
# Fit 1: m_w = a*x^b
#########################

# Fit the data to an exponential decay curve with error bars
popt1, pcov1 = sciop.curve_fit(lambda t,a,b: a*t**b,  x,  y,  p0=(1, -1), sigma=e)
error1 = np.sqrt(np.diag(pcov1))

# Print results to screen
a = popt1[0]
b = popt1[1]
print("\nFor fit of the form f(x) = a*x^b:")
print("a = ", a, "\t +/- \t", error1[0])
print("b = ", b, "\t +/- \t", error1[1])

# x and y values for the fit curve
xfit1 = np.linspace(2.3, 2.9)
yfit1 = fit1(xfit1, popt1[0], popt1[1])

#########################
# Fit 2: m_w = c + a*x^b
#########################

# Fit the data to an exponential decay curve with error bars
popt2, pcov2 = sciop.curve_fit(lambda t,a,b,c: a + b*t**c,  x,  y,  p0=(0.1, 1, -1), sigma=e)
error2 = np.sqrt(np.diag(pcov2))

c1 = popt2[0]
c2 = popt2[1]
c3 = popt2[2]
print("\nFor fit of the form m = c + a*x^b:")
print("c = ", c1, "\t +/- \t", error2[0])
print("a = ", c2, "\t +/- \t", error2[1])
print("b = ", c3, "\t +/- \t", error2[2])

# x and y values for the fit curve
xfit2 = np.linspace(2.3, 2.9)
yfit2 = fit2(xfit2, popt2[0], popt2[1], popt2[2])

#########################
# Plot Results
#########################

plt.rc('text', usetex=True)
plt.errorbar(x, y, yerr=e, ls='none', label="Original Data")

label1 = "Fit1: " + r"$f(x)=a x^{b}$"
plt.plot(xfit1, yfit1, label=label1)

label2 = "Fit2: " + r"$f(x)=c + a x^{b}$"
plt.plot(xfit2, yfit2, label=label2)

plt.legend(loc=1)
plt.xlabel(r"$x$")
plt.ylabel(r"$f(x)$")
plt.title("Data with Exponential Fits")
plt.show()
