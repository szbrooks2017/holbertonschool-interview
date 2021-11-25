#!/usr/bin/python3
"""
function that returns an integer
if n is impossible return 0
"""


def minOperations(n):
    """ function that finds the min ops"""

    i = 2
    result = 0

    if (n <= 0):
        return 0

    while (i <= n):
        while (n % i == 0):
            result += i
            n = n / i
        i += 1
    return result
