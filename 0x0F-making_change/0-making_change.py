#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """ return fewest number of coins"""
    if (total == 0):
        return 0
    coins.sort()
    coins.reverse()
    change = 0
    for coin in coins:
        divided = total // coin
        change += divided
        total -= (divided * coin)
    if total != 0:
        return -1
    return change
