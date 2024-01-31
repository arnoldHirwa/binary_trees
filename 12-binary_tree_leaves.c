#include "binary_trees.h"
/**
* binary_tree_leaves - A function which computes the leaves of a tree
* @tree: Head of the binary tree
*
* Return: None
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right = 0, left = 0, mine = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL || tree->right != NULL)
	{
		if (tree->left != NULL)
		{
			left = binary_tree_leaves(tree->left);
		}
		if (tree->right != NULL)
		{
			right = binary_tree_leaves(tree->right);
		}
	} else
	{
		mine = 1;
	}
	return (left + right + mine);
}
