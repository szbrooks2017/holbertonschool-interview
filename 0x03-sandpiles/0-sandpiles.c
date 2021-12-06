#include "sandpiles.h"
/**
 * print_grid - Print 3i3 grid
 * @grid: 3i3 grid
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
 * add_sandpile_matrix - function that adds a 3i3 sandpile
 * @grid1: a 3i3 matrii
 * @grid2: a 3i3 matrii
 * Return: 1 if the sandpile is unstable otherwhise will return 0
 */
int add_sandpile_matrix(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;
	int isUnstable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;

			if (grid1[i][j] > 3)
				isUnstable = 1;
		}
	}

	return (isUnstable == 0 ? 0 : 1);
}
/**
 * toppling_sandpiles - function that topples a sandpile
 * @grid1: a 3i3 matrii
 * @grid2: a 3i3 matrii
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");
	print_grid(grid1);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if (i + 1 < 3)
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
/**
 * sandpiles_sum - function that sums two sandpiles
 * @grid1: first grid of sandpiles
 * @grid2: second grid of sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int isUnstable = 0;

	isUnstable = add_sandpile_matrix(grid1, grid2);
	while (isUnstable != 0)
	{
		toppling_sandpiles(grid1, grid2);
		isUnstable = add_sandpile_matrix(grid1, grid2);
	}

}