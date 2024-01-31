#include "binary_trees.h"

/**
* binary_tree_uncle - Finds uncle of a given node
* @node: A node whose sibling we are going to return
*
* Return: A sibling of a node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent = NULL, *grandPa = NULL;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandPa = parent->parent;
	if (grandPa->right == parent)
		return (grandPa->left);
	else if (grandPa->left == parent)
		return (grandPa->right);
	return (NULL);
}
