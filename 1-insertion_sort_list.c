#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nxt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = nxt = (*list)->next;

	for (; nxt; current = nxt)
	{
		for (nxt = nxt->next; current->prev && current->n
				< current->prev->n;
		      print_list(*list))
		{
			current->prev->next = current->next;

			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
		}
	}
}
