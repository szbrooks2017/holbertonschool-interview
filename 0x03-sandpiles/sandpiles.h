#ifndef SANDPILES_H
#define SANDPILES_H

/* libraries */
#include <stdlib.h>
#include <stdio.h>

/* prototypes */
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int *grid);
void topple(int *grid);

#endif