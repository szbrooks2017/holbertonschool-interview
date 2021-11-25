#!/usr/bin/python3

def minOperations(n):

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
