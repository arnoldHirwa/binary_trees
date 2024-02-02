#include "binary_trees.h"

/**
* binary_traverse - A function which traverse a binary tree in inorder
* @failed: check if the condition failed
* @tree: The head ot the tree
*
* Return: 1 success, 0 otherwise
*/

int binary_traverse(binary_tree_t *tree, bool *failed)
{
	int left, right;

	binary_tree_t *parent;

	if (*failed == true)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);
	if (tree->left != NULL)
	{
		left = binary_traverse(tree->left, failed);
		if (tree->n <= left)
		{
			*failed = true;
			return (0);
		}
	}
	if (tree->right != NULL)
	{
		right = binary_traverse(tree->right, failed);
		if (tree->n >= right)
		{
			*failed = true;
			return (0);
		}
	}

	parent = tree->parent;
	if (parent == NULL)
		return (1);
	if (parent->right == tree)
	{
		if (tree->left != NULL)
			return (tree->n < left ? tree->n : left);
		return (tree->n);
	}
	if (tree->right != NULL)
		return (tree->n > right ? tree->n : right);
	return (tree->n);
}

/**
* binary_tree_is_bst - Finds a whether a tree is a valid BST
* @tree: A top node of the tree
*
* Return: 1 if it is valid, 0 otherwise
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	bool failed = false;

	if (tree == NULL)
		return (0);
	binary_traverse((binary_tree_t *)tree, &failed);

	if (failed == true)
		return (0);

	return (1);
}
