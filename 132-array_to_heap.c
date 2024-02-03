#include "binary_trees.h"

/**
* array_to_heap - create a alv from an array
* @array: array which holds data
* @size: size of the array
* Return: pointer to the root of the created tree.
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i = 0;

	if (array == NULL)
		return (NULL);

	for (i = 0 ; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}

	return (root);
}
