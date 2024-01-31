#include "binary_trees.h"

/**
* binary_tree_preorder - A function which traverse a binary tree in pre-order
* @tree: Head of the binary tree
* @func: Function to be called with the value of a node
*
* Return: None
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	func(tree->n);
	if (tree->left != NULL)
	{
		binary_tree_preorder(tree->left, func);
	}
	if (tree->right != NULL)
	{
		binary_tree_preorder(tree->right, func);
	}
}
