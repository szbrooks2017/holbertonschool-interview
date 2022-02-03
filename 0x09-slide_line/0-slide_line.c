#include "slide_line.h"

/**
 * slide_line - a function that slides and merges an int array
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 * @direction: is either the left or right macro
 * Return: returns 1 for success or 0 if failed
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != 0 && direction != 1)
		return (0);
	if (line == NULL || size < 1)
		return (0);

	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);

	return (1);
}

/**
 * slide_left - slides to the left
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 */
void slide_left(int *line, size_t size)
{

}

/**
 * slide_right - slides to the right
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 */
void slide_right(int *line, size_t size)
{
	
}
