#include "binary_trees.h"

/**
* nbr_nodes - Calculates nbr of nodes of a tree
* @tree: A tree whose nodes we are going to count
*
* Return: number of nodes
*/

int nbr_nodes(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + nbr_nodes(tree->left) + nbr_nodes(tree->right));
}


/**
* heap_to_sorted_array - creates a sorted array from a binary heap
* @heap: pointer to the root of the heap
* @size: Address to store the size of the array
* Return: Pointer to the first element of the array
*/

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	size_t i;

	*size = nbr_nodes(heap);
	array = malloc(*size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < *size; i++)
	{
		array[i] = heap_extract(&heap);
	}
	return (array);
}
