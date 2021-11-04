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

    match = [0]
    totalBoxes = len(boxes)

    if len(boxes) == 0:
        return True

    for item in match:
        for key in boxes[item]:
            if key not in match and key < totalBoxes:
                match.append(key)
            print(match)
    return len(match) == totalBoxes
    # for index in enumerate(match):
    #     print(index)
    #     if index in match:
    #         return True
    #     else:
    #         return False
