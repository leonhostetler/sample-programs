#! /usr/bin/env python
"""
A very simple program to print the primes less than n.

Leon Hostetler, Jan. 26, 2017

USAGE: python primes.py
"""
from __future__ import division, print_function
import numpy as np

n = 1000

# Checks to see if a number is prime
def is_prime(n):
    for i in range(2,n):
        if n % i == 0:
            return False    # Return false if divisible by any smaller number
            break
    return True            # Return true if not divisible by any smaller number


for i in range(2,n):
    if is_prime(i):
        print(i)
