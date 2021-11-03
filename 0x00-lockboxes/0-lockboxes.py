#!/usr/bin/python3

"""
    n number of locked boxes, each box is numbered 0 to n - 1,
    each box may contain keys to other boxes
    canUnlock - method that determines if all the boxes can be opened
    @boxes: is a list of lists
    - key with the same number as a box opens that box
    - keys are all positive
    - some keys do not have boxes
    - boxes[0] is unlocked
    Return: true if all boxes can be opened, else false
"""


def canUnlockAll(boxes):
    """ canUnlockAll checks to see if all boxes can be unlocked"""
    # iterate through the list of lists
    # if total boxes or items in boxes are empty return false
    # append to new list
    # if there is a match then return true

    match = []
    totalBoxes = len(boxes)

    for keys in boxes:
        if len(keys) == 0 and keys is not boxes[totalBoxes - 1]:
            return False
        for item in keys:
            match.append(item)
    for index in enumerate(boxes):
        if index in match or index < totalBoxes - 1:
            return True
        else:
            return False
