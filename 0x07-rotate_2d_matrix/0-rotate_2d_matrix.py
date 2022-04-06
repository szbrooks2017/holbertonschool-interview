#!/usr/bin/python3

"""
rotate_2d_matrix - rotates a 2d matrix in place
Return: nothing
"""


def rotate_2d_matrix(matrix):
    "find the length of the matrix"

    # k, temp = 0, 0
    # angle = 90
    # row = len(matrix)
    # column = len(matrix[0])
    # rotate = [[math.cos(angle), math.sin(angle)],
    #            [-1 * math.sin(angle), math.cos(angle)]]

    # for i in range(column):
    #     for j in range(i, column):
    #         temp = 0
    #         while k < 2:
    #             temp += round(matrix[i][k] * rotate[k][j])
    #             k = k + 1
    #     matrix[i][j] = temp

    row = len(matrix)
    # transpose
    for i in range(row):
        for j in range(i, row):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # reverse
    n = len(matrix)
    for i in range(n//2):
        for j in range(n):
            matrix[j][i], matrix[j][n-1-i] = matrix[j][n-1-i], matrix[j][i]
