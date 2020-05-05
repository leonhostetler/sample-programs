#! /usr/bin/env python
"""
A very simple program to print the triplet primes less than n.

Leon Hostetler, Jan. 26, 2017

USAGE: python primes_triplets.py
"""
from __future__ import division, print_function

n = 1000


# Checks to see if a number is prime
def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False    # Return false if divisible by any smaller number
            break
    return True             # Return true if not divisible by any smaller number


# Print all the triplet primes less than a million
counter = 0
for i in range(2, n):
    if is_prime(i) and is_prime(i+2) and is_prime(i+6):
        print(i, ", ", i+2, ", ", i+6, sep="")
        counter += 1
    if is_prime(i) and is_prime(i+4) and is_prime(i+6):
        print(i, ", ", i+4, ", ", i+6, sep="")
        counter += 1

print()
print("There are ", counter, " prime triplets less than ", n, ".")
