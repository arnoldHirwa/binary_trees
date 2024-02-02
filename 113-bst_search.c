#include "binary_trees.h"
/**
 * bst_search - search a value in bst
 * @tree: the root of the tree
 * @value: the value to search
 *
 * Return: The node whose n is equal to value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = NULL;

	if (!tree)
		return (NULL);

	current = (bst_t *)tree;
	while (current)
	{
		if (current->n == value)
			return (current);
		if (current->n > value)
			current = current->left;
		else
			current = current->right;
	}

	return (NULL);
}
