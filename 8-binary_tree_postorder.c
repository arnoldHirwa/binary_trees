#include "binary_trees.h"

/**
* binary_tree_postorder - A function which traverse a binary tree in postorder
* @tree: Head of the binary tree
* @func: Function to be called with the value of a node
*
* Return: None
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	if (tree->left != NULL)
	{
		binary_tree_postorder(tree->left, func);
	}
	if (tree->right != NULL)
	{
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
