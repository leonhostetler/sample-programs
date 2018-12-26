#! /usr/bin/env python
"""

We have a text file (observables.txt) containing the P, L, and s observables from all lattice sizes and beta values. We want to plot P and Pe (i.e. P and P error) versus kappa, but only for the 64x12 lattices at a specific beta value. We want to do the same for the L and s observables. For each lattice size, we have eight beta values. So from the text file, we extract eight smaller text files, which serve as inputs to gnuplot. Doing the data sorting, grouping, and copy/pasting into the smaller data files takes a long time, so this script was written to automate it.

The input text file has the headers:

    lattice    njob    beta    kappa   L     Le   P    Pe   s    se

"""

import numpy as np

# Import the data from the text file. Commented rows are not imported.
data = np.genfromtxt("observables.txt", comments='#', usecols=(0,1,2,3,4,5,6,7,8,9), dtype=str)

# Make a new array containing all rows of data that have
# "064x12" as the value in the first column. 
# The rest of the rows are ignored, as we don't care
# about the other lattice sizes right now.
latt64x12 = data[np.where(data[:,0] == "064x12")]

# From this array, make a smaller array for each beta (third column) value
beta2p30 = latt64x12[np.where(latt64x12[:,2] == "2.3000")]
beta2p40 = latt64x12[np.where(latt64x12[:,2] == "2.4000")]
beta2p50 = latt64x12[np.where(latt64x12[:,2] == "2.5000")]
beta2p60 = latt64x12[np.where(latt64x12[:,2] == "2.6000")]
beta2p70 = latt64x12[np.where(latt64x12[:,2] == "2.7000")]
beta2p80 = latt64x12[np.where(latt64x12[:,2] == "2.8000")]
beta2p90 = latt64x12[np.where(latt64x12[:,2] == "2.9000")]
beta3p00 = latt64x12[np.where(latt64x12[:,2] == "3.0000")]

# Print all to text files for plotting
np.savetxt("beta2p30.d", beta2p30, fmt='%s')
np.savetxt("beta2p40.d", beta2p40, fmt='%s')
np.savetxt("beta2p50.d", beta2p50, fmt='%s')
np.savetxt("beta2p60.d", beta2p60, fmt='%s')
np.savetxt("beta2p70.d", beta2p70, fmt='%s')
np.savetxt("beta2p80.d", beta2p80, fmt='%s')
np.savetxt("beta2p90.d", beta2p90, fmt='%s')
np.savetxt("beta3p00.d", beta3p00, fmt='%s')
