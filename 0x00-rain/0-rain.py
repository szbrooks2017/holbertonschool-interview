#!/usr/bin/python3

def rain(walls):
    water = 0
    if len(walls) == 0:
        return 0
    middle = int(len(walls) / 2)
    for i in range(len(walls)):
        if i != 0 and i != (len(walls) - 1):
            l = max(walls[0:middle])
            r = max(walls[middle:len(walls)])
            least = min(l, r)
            if least - walls[i] >= 0:
                water += least - walls[i]
            else:
                water += 0
    return water
