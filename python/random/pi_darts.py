#! /usr/bin/env python
"""
This program approximates pi by "throwing darts" randomly at a circle
and counting the number that land inside.

Leon Hostetler, May 6, 2016

USAGE: python pi_darts.py
"""
from __future__ import division, print_function
import matplotlib.pyplot as plt
import numpy as np
import random

listx = []      # Lists for the x and y coordinates of the darts
listy = []

r = 2.0         # radius of circle
darts = 10000   # number of darts to throw
inside = 0      # counts the number that land inside the circle

random.seed()

for x in range(0,darts):
    x = random.random()*2*r-r
    y = random.random()*2*r-r
    listx.append(x)
    listy.append(y)
    if(np.sqrt(x**2+y**2) <= r):
        inside += 1

print ("Radius is :", r)
print ("Actual area: ", np.pi*r*r)
print ("Approximated area: ", inside/darts * (2.0*r)**2)
print ("Approximated pi: ", inside/darts * 4.0)

# Plot the results
plt.axis('equal')
plt.axis([-r, r, -r, r])    #Adjust graph dimensions here
plt.title('Throwing Darts')
plt.grid(True)
plt.scatter(listx, listy, c='blue', s=1,edgecolors='none')
circle = plt.Circle((0, 0), r, fill=False) # Black-bordered circle
plt.gca().add_patch(circle)
plt.show()
