#! /usr/bin/env python
"""
A very simple program to print the palidromic primes less than n.

Leon Hostetler, Jan. 26, 2017

USAGE: python primes_palindromic.py
"""
from __future__ import division, print_function


n = 100000

# Checks to see if a number is prime
def is_prime(n):
    for i in range(2,n):
        if n % i == 0:
            return False    # Return false if divisible by any smaller number
            break
    return True             # Return true if not divisible by any smaller number


# Checks if a number is palindromic
def is_palindromic(num):
    digits = list(map(int, str(num)))
    rev_digits = digits[:]
    rev_digits.reverse()

    if digits == rev_digits:
        return True

    return False


# Print all the palindromic primes less than a million
for n in range(10, n):
    if is_palindromic(n):
        if is_prime(n):
            print(n)
