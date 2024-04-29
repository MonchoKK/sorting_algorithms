#include "sort.h"
#include <stdio.h>


static listint_t *find_insertion_point(listint_t *current);

static void insert_node(listint_t **list, listint_t *current,
		listint_t *insertion_point);

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

		insert_node(list, current, insertion_point);

		current = next;


		print_list(*list);
	}
}


/**
 * find_insertion_point - Finds the insertion point for a
 *	node in a sorted linked list.
 * @current: Pointer to the current node to be inserted
 * This function iterates through the nodes preceding the
 *	current node find the correct insertion point
 *	int the sorted linked list.
 * Return: A pointer to the node before which the current node
 *	should be inserted.
 */

static listint_t *find_insertion_point(listint_t *current)
{
	listint_t *insertion_point = current->prev;


	while (insertion_point != NULL && insertion_point
				->n > current->n)
	{
		insertion_point = insertion_point->prev;
	}


	return (insertion_point);

}

static void insert_node(listint_t **list, listint_t *current,
		*insertion_point)
{
	if (insertion_point == NULL)
	{
		(*list)->prev = current;
		current->next = *list;
		current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
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
}
