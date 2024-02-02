#include "binary_trees.h"

/**
* binary_traverse - A function which traverse a binary tree in inorder
* @tree: The head ot the tree
* @min: The minimum value a node can have
* @max: The maximum value a node can have
*
* Return: 1 success, 0 otherwise
*/

int binary_traverse(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_traverse(tree->left, min, tree->n - 1)
		&& binary_traverse(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_bst - Finds a whether a tree is a valid BST
* @tree: A top node of the tree
*
* Return: 1 if it is valid, 0 otherwise
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_traverse((binary_tree_t *)tree, -2147483648, 2147483647));
}
