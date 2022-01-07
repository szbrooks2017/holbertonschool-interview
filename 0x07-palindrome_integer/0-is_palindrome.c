#include "palindrome.h"

/**
 * is_palindrome - checks if it an int is a palindrome
 * @n: is the integer to check
 * Return: 1 if n is a palindrome else 0
 */

int is_palindrome(unsigned long n)
{
	int temp, i, sum = 0;

	temp = n;

	while (n > 0)
	{
		i = n % 10;
		sum = (sum * 10) + i;
		n = n / 10;
	}
	if (temp == sum)
	{
		return (1);
	}
	else
	{
		return (0);
		}
}
