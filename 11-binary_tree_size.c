#include "binary_trees.h"
/**
* binary_tree_size - A function which computes the size of a tree
* @tree: Head of the binary tree
*
* Return: None
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		left = binary_tree_size(tree->left);
	}
	if (tree->right != NULL)
	{
		right = binary_tree_size(tree->right);
	}

	return (right + left + 1);
}
