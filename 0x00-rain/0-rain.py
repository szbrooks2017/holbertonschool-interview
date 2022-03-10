#!/usr/bin/python3
"""0-rain"""


def rain(walls):
    """rain function"""

    if len(walls) == 0:
        return 0
    left, right = 0, len(walls) - 1
    leftMax, rightMax = walls[left], walls[right]
    water = 0

    while left < right:
        if leftMax < rightMax:
            left += 1
            leftMax = max(leftMax, walls[left])
            water += leftMax - walls[left]
        else:
            right -= 1
            rightMax = max(rightMax, walls[right])
            water += rightMax - walls[right]
    return water
