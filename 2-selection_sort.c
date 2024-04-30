#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *	using the Selection algorithm
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;


	if (array == NULL || size < 2)
		return;


	for (i = 0; i < size - 1; i++)
	{
		size_t min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			int temp = array[i];

			array[i] = array[min];
			array[min] = temp;


			print_array(array, size);
		}
	}
}
