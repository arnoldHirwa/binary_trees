#include "binary_trees.h"

/**
* binary_tree_rotate_right - Rotate a tree to the right
* @tree: A tree to rotate
*
* Return: A new root node of the tree
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL, *new_left_child = NULL;

	if (tree == NULL)
		return (NULL);

	new_parent = tree->left;
	if (new_parent == NULL)
		return (tree);

	new_left_child = new_parent->right;

	tree->left = new_left_child;
	tree->parent = new_parent;
	new_parent->right = tree;
	new_parent->parent = NULL;

	return (new_parent);
}
