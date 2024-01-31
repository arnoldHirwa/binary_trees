#include "binary_trees.h"


/**
* binary_search - Computes whether a tree is full or not
* @tree: Head of the binary tree
*
* Return: 1 if the tree can't be full
*/

int binary_search(const binary_tree_t *tree)
{

	int count = 0, left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		count += 1;

	if (tree->right != NULL)
		count += 1;

	if (count == 0 || count == 2)
	{
		if (count == 2)
		{
			left = binary_search(tree->left);
			right = binary_search(tree->right);
		}
		return (left + right);
	}
	return (1);
}

/**
* binary_tree_is_full - Computes whether a tree is full or not
* @tree: Head of the binary tree
*
* Return: 1 if the tree can't be full
*/

int binary_tree_is_full(const binary_tree_t *tree)
{

	int count;

	if (tree == NULL)
		return (0);

	count = binary_search(tree);

	return (count == 0 ? 1 : 0);
}
