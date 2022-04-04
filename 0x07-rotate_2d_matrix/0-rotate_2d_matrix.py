#!/usr/bin/python3
import math

"""
rotate_2d_matrix - rotates a 2d matrix in place
Return: nothing
"""


def rotate_2d_matrix(matrix):
    "find the length of the matrix"

    row = len(matrix)
    column = len(matrix[0])
    # rotate = [[math.cos(90), math.sin(90)],
    #           [-1 * math.sin(90), math.cos(90)]]
    # transpose
    for i in range(row):
        for j in range(column):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # reverse
    n = len(matrix)
    for i in range(n//2):
        for j in range(n):
            matrix[j][i], matrix[j][n-1-i] = matrix[j][n-1-i], matrix[j][i]
    return matrix
