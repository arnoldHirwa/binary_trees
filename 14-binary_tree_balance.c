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
* binary_tree_balance - A function which computes the height of a tree
* @tree: Head of the binary tree
*
* Return: None
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left = binary_tree_count(tree->left) - 1;
	size_t right = binary_tree_count(tree->right) - 1;

	return (left - right);
}
