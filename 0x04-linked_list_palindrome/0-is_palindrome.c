#include "lists.h"

/**
 * is_palindrome - checks a singly linked list for palindromes
 * @head: is the singly linked list
 * Return: 0 if not a palindrome, 1 if it is.
 */
int is_palindrome(listint_t **head)
{
	listint_t **top;
	listint_t *bot;
	int result = 0;

	if (!head)
	{
		return (0);
	}
	if (!*head)
	{
		return (1);
	}
	top = head;
	bot = *head;
	result = recursive(top, bot);
	return (result);

}

/**
 * recursive - recursively tells if a linked list is a palindrome
 * @top: top bit of value to check
 * @bot: bottom bit of value to check
 * Return: 1 or 0
 */
int recursive(listint_t **top, listint_t *bot)
{
	int result = -1;
	int output = -1;

	if (bot == NULL)
		return (1);
	result = recursive(top, bot->next);
	if (result == 0)
		return (0);
	if ((*top)->n == bot->n)
		output = 1;
	else
		output = 0;
	*top = (*top)->next;
	return (output);
}
