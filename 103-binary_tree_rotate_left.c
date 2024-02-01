#include "binary_trees.h"

/**
* binary_tree_rotate_left - Rotate a tree to the left
* @tree: A tree to rotate
*
* Return: A new root node of the tree
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL, *new_right_child = NULL;

	if (tree == NULL)
		return (NULL);

	new_parent = tree->right;
	if (new_parent == NULL)
		return (tree);

	new_right_child = new_parent->left;

	tree->right = new_right_child;
	tree->parent = new_parent;
	new_parent->left = tree;
	new_parent->parent = NULL;

	return (new_parent);
}
