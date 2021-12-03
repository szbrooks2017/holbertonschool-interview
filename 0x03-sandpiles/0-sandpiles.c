#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * topple - Topples up, down, left, right
 * 
 * @grid: sandpile pointer
 * 
 * Return: returns 0 if stable, 1 if not
 */
void topple(int *grid)
{
	int new[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (*(grid + i) > 3)
			{
				*(grid + i) -= 4;
				if(i > 0)
					new[i - 1][j] += 1;
				if (i < 2)
					new[i + 1][j] += 1;
				if (j > 0)
					new[i][j - 1] += 1;
				if (j < 2)
					new[i][j + 1] += 1;
			}
		}
	}
}

/**
 * @brief checks for stablitity
 * 
 * @param grid to check
 * @return int, 0 if stable, 1 if not
 */

int is_stable(int *grid)
{
	int i, stable = 0;

	for (i = 0; i < 9; i++)
	{
		if (*(grid + i) > 3)
			stable = 1;
	}
	return (stable);
}
/**
 * sandpiles_sum - sum of two sandpiles
 * 
 * @param grid1 sandpile one
 * @param grid2 sandpile two
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int *grid3 = &grid1[0][0];
	int i, j, stable = 0;

	for (i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
			{
				stable = 1;
			}
		}
	}
	while (stable)
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid3);
		stable = is_stable(grid3);
	}
}