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
void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	printf("=\n");
	print_grid(grid1);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if(i + 1 < 3)
					grid2[i + 1][j]++;
				if (i - 1 >= 0)
					grid2[i - 1][j]++;
				if (j + 1 < 3)
					grid2[i][j + 1]++;
				if (j - 1 >= 0)
					grid2[i][j - 1]++;
			}
		}
	}
}

// /**
//  * @brief checks for stablitity
//  * 
//  * @param grid to check
//  * @return int, 0 if stable, 1 if not
//  */

// int is_stable(int *grid)
// {
// 	int i, stable = 0;

// 	for (i = 0; i < 9; i++)
// 	{
// 		if (*(grid + i) > 3)
// 			stable = 1;
// 	}
// 	return (stable);
// }

int add_sandpile_matrix(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int stable;
	for (i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
			if (grid1[i][j] > 3)
			{
				stable = 1;
			}
		}
	}
	return (stable == 0 ? 0 : 1);
}
/**
 * sandpiles_sum - sum of two sandpiles
 * 
 * @param grid1 sandpile one
 * @param grid2 sandpile two
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	// int *grid3 = &grid1[0][0];
	int stable = 0;
	stable = add_sandpile_matrix(grid1, grid2);

	while (stable != 0)
	{
		topple(grid1, grid2);
		add_sandpile_matrix(grid1, grid2);
	}
}