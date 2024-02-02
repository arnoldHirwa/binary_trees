#include "binary_trees.h"
/**
* array_to_bst - create a bst from an array
* @array: array which holds data
* @size: size of the array
* Return: pointer to the root of the created tree.
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i = 0;

	if (array == NULL)
		return (NULL);

	for (i = 0 ; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}
