#include "main.h"
/**
 * print_liststr - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t print_liststr(const list_st *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
