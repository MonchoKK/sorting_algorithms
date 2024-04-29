#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *	ascending oder using Insertion sort algrithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insertion_point = NULL;
        listint_t *next = NULL;
        listint_t *current = NULL;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;
		next = current->next;

		while (insertion_point != NULL && insertion_point
				->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}

		if (insertion_point == NULL)
		{
			(*list)->prev = current;
			current->next = *list;
			current->prev->next = next;
			if (next != NULL)
				next->prev = current->prev;
			current->prev = NULL;
			*list = current;
		}
		else if (insertion_point->next != current)
		{
			current->next = insertion_point->next;
			current->prev = insertion_point;
			if (insertion_point->next != NULL)
				insertion_point->next->prev = current;
			insertion_point->next = current;
			current->next->prev = current;
		}

		current = next;

		print_list(*list);
	}
}
