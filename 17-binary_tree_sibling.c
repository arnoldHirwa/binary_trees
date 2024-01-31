#include "binary_trees.h"

/**
* binary_tree_sibling - Finds a sibling of a given node
* @node: A node whose sibling we are going to return
*
* Return: A sibling of a node
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent->right == node)
		return (parent->left);
	else if (parent->left == node)
		return (parent->right);
	return (NULL);
}
