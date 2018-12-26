#! /usr/bin/env python
"""

Example of a script that accepts a command line variable.

Leon Hostetler, June 9, 2018

USAGE: python commandline.py string

"""

from __future__ import division, print_function
import sys

# Get the string from the command line
string = str(sys.argv[1])

print("You wrote \"", string, "\"")
