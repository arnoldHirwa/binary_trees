#include "binary_trees.h"

/**
* max - finds the biggest number
* @a: the first number
* @b: the second number
*
* Return: The biggest value between a and b
*/

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
* binary_tree_count - A function which computes the height of a tree
* @tree: Head of the binary tree
*
* Return: None
*/

int binary_tree_count(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		left = binary_tree_count(tree->left);
	}
	if (tree->right != NULL)
	{
		right = binary_tree_count(tree->right);
	}

	return (max(right, left) + 1);
}

/**
* binary_tree_height - A function which computes the height of a tree
* @tree: Head of the binary tree
*
* Return: None
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	int size = binary_tree_count(tree) - 1;

	return (size >= 0 ? size : 0);
}
