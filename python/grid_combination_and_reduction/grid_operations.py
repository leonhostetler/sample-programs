#! /usr/bin/env python
"""
Suppose one has two grids. Each grid consists of some number of
evenly spaced numbers, however, the grid spacing may not be the
same. We want a (smallest) third grid of evenly spaced numbers
that contains all the numbers of the previous two grids.

In the end, we want to be able to slice the fine grid in some way
to return our original grids.

This kind of thing is useful as follows: Suppose we have experimental
data on different grids. We want to be able to fit some
common function through both data sets. In the end, we may want to be
able to project back to the original grids for some reason, for example,
to directly compare a some function of the third grid against the
experimental data.

"""
import sys 
import numpy as np



def downsample(fine_grid, coarse_grid):
   """Downsample a fine grid to fit on
   a coarse grid. Assumes even spacing in the grids."""
   
   eps = 0.000000001
   
   fine_grid_spacing = fine_grid[1]-fine_grid[0] # Assumes even spacing
   coarse_grid_spacing = coarse_grid[1]-coarse_grid[0]
   
   start = np.argwhere(abs(fine_grid-coarse_grid[0])<eps)[0][0]
   every_n = int(round(coarse_grid_spacing/fine_grid_spacing,0))
   
   proj = fine_grid[start::every_n][:len(coarse_grid)]
   
   return proj
    

def downsample_fn(fine_grid_fn, fine_grid, coarse_grid):
   """Downsample a function of a fine grid to fit on
   a coarse grid. Assumes even spacing in the grids."""
   
   eps = 0.000000001
   
   fine_grid_spacing = fine_grid[1]-fine_grid[0] # Assumes even spacing
   coarse_grid_spacing = coarse_grid[1]-coarse_grid[0]
   
   start = np.argwhere(abs(fine_grid-coarse_grid[0])<eps)[0][0]
   every_n = int(round(coarse_grid_spacing/fine_grid_spacing,0))
   
   proj = fine_grid_fn[start::every_n][:len(coarse_grid)]
   
   print(len(fine_grid_fn), start, every_n, len(coarse_grid), len(proj))
   
   return proj
   

def downsample2(fine_grid, coarse_grid):
   """Alternative approach that does not assume even
   spacing in the coarse grid. This approach is very
   slow for large grids."""
   
   ind = fine_grid.searchsorted(coarse_grid)
   
   return fine_grid[ind]
   

def downsample2_fn(fine_grid_fn, fine_grid, coarse_grid):
   """Alternative approach that does not assume even
   spacing in the coarse grid. This approach is very
   slow for large grids."""
   
   ind = fine_grid.searchsorted(coarse_grid)
   
   return fine_grid_fn[ind]




# Coarse grids
# Each grid is defined by the first point, the total number of points, and the grid spacing
grid1_i, grid1_N, grid1_a = 1.0, 10, 2.0
grid2_i, grid2_N, grid2_a = 2.8, 15, 1.5

grid1 = np.linspace(grid1_i, grid1_i+grid1_a*(grid1_N-1), grid1_N, endpoint=True)
grid2 = np.linspace(grid2_i, grid2_i+grid2_a*(grid2_N-1), grid2_N, endpoint=True)

print("\ngrid1:", grid1)
print("grid2:", grid2)


# Construct the fine grid
# One wants a grid spacing such that the fine grid contains all
# points from both coarse grids. The simplest way to do this is
# by just looking at the number of decimal places in grid1_a and
# grid2_a and choosing the appropriate power of 10
grid3_a = 0.1
grid3_i = min(grid1[0], grid2[0])
grid3_f = max(grid1[-1], grid2[-1])
grid3_N = int((grid3_f-grid3_i)/grid3_a)+1

#grid3 = np.linspace(grid3_i, grid3_f, grid3_N, endpoint=True)
# arange seems to work better than linspace for this
# to include the endpoint, the second argument needs to be endpoint+grid spacing
grid3 = np.arange(grid3_i, grid3_f+grid3_a, grid3_a) 

print("\ngrid3:", grid3)


# Projection back to course grids
grid1_p = downsample(grid3, grid1)
grid2_p = downsample(grid3, grid2)
print("\nMethod 1:")
print("grid1_p:", grid1_p)
print("grid2_p:", grid2_p)


grid1_p = downsample2(grid3, grid1)
grid2_p = downsample2(grid3, grid2)
print("\nMethod 2:")
print("\ngrid1_p:", grid1_p)
print("grid2_p:", grid2_p)



# Check that they're the same
#print("")
#print(grid1-grid1_p)
#print(grid2-grid2_p)























