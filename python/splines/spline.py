#! /usr/bin/env python
"""

Finite difference derivatives amplify any error that is present in the
input data. For example, the h^2 in the denominator of the finite difference
second derivative amplifies any input error by a factor of 1/h^2, so as
h -> 0, this error becomes large.

Typical experimental or Monte Carlo data contains input errors, which
make it difficult to obtain smooth second or higher derivatives from the data
via finite difference methods. The solution can be to smooth the data (either
at the level of the original data or at a later derivative) via splines.

USAGE:
	python spline.py

"""
#import sys 
import numpy as np
#from scipy.interpolate import splrep, BSpline
from scipy import interpolate
import matplotlib.pyplot as plt
plt.rcParams.update({'font.size': 6})
plt.rcParams['figure.figsize'] = 3.0,4.0


def firstder(vec, h):
    """Return the first-derivative (finite difference) 
       of the given vector with truncation error O(h^2) for
       the edge points and O(h^2) for the bulk points
    """
    der = np.zeros((len(vec)))
    
    # Use 3pt foward difference for first point
    der[0] = (-3*vec[0]+4*vec[1]-vec[2])/(2*h)
    
    # Use 2pt central difference for bulk elements
    for i in range(1,len(vec)-1):
        der[i] = (vec[i+1]-vec[i-1])/(2*h)
               
    # Use 3pt backward difference for last point
    der[-1] = (3*vec[-1]-4*vec[-2]+vec[-3])/(2*h)
    
    return der


def secondder(vec, h):
    """Return the second-derivative (finite difference) 
       of the given vector with truncation error O(h) for
       the edge points and O(h^2) for the bulk points
    """
    der = np.zeros((len(vec)))
    
    # Use 3pt foward difference for first point
    der[0] = (vec[0]-2*vec[1]+vec[2])/h**2
    
    # Use 3pt central difference for bulk elements
    for i in range(1,len(vec)-1):
        der[i] = (vec[i-1]-2.0*vec[i]+vec[i+1])/h**2
               
    # Use 3pt backward difference for last point
    der[-1] = (vec[-1]-2*vec[-2]+vec[-3])/h**2
    
    return der


##################### MAIN PART #####################

# Import raw data
data = np.genfromtxt('data.txt')
x = data[:,0]
y = data[:,1]

# Finite difference derivatives of the data
dy_fd = firstder(y, x[1]-x[0])
ddy_fd = secondder(y, x[1]-x[0])

# Compute a spline for the raw data
tck = interpolate.splrep(x, y, k=5, s=0.0005)
print("t =", tck[0])
print("c =", tck[1])
print("k =", tck[2])

# Fine grid
new_x = np.linspace(x[0], x[-1], 1000)

# Get spline function and its derivatives
new_y = interpolate.splev(new_x, tck, der=0) # The original function (spline)
dy = interpolate.splev(new_x, tck, der=1) # The first derivative of the spline
ddy = interpolate.splev(new_x, tck, der=2) # The second derivative of the spline


# Plot results
ms=0.3 # markersize for finite difference
lw=0.1 # linewidth for finite difference
slw=0.5 # linewidth for splines

plt.rc('text', usetex=True)
fig, (ax1, ax2, ax3) = plt.subplots(nrows=3, ncols=1, sharex=True)

ax1.plot(x, y, marker="s", label="raw data", color='blue', markersize=ms, linewidth=lw)
ax1.plot(new_x, new_y, '-', label='spline', markersize=0, linewidth=slw, color='red')
ax1.set(ylabel=r'$y$')
ax1.legend(loc=2)

ax2.plot(x, dy_fd, marker="s", label="finite difference", color='blue', markersize=ms, linewidth=lw)
ax2.plot(new_x, dy, '-', label='spline', markersize=0, linewidth=slw, color='red')
ax2.set(ylabel=r'$dy/dx$')
ax2.legend(loc=2)

ax3.plot(x, ddy_fd, marker="s", label="finite difference", color='blue', markersize=ms, linewidth=lw)
ax3.plot(new_x, ddy, '-', label='spline', markersize=0, linewidth=slw, color='red')
ax3.set(ylabel=r'$d^2y/dx^2$')
ax3.set(xlabel=r'$x$')
ax3.legend(loc=3)

fig.subplots_adjust(left=0.2) 
fig.subplots_adjust(right=0.95) 
fig.subplots_adjust(top=0.95)
fig.subplots_adjust(bottom=0.13)
plt.savefig("spline.pdf")
