#include "binary_trees.h"
/**
* binary_tree_nodes - Computes nodes which are not leaves in a tree
* @tree: Head of the binary tree
*
* Return: None
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t right = 0, left = 0, mine = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		left = binary_tree_nodes(tree->left);
	    mine = 1;
	}
	if (tree->right != NULL)
	{
		right = binary_tree_nodes(tree->right);
	    mine = 1;
	}
	return (left + right + mine);
}
