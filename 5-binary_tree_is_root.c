#include "binary_trees.h"

/**
* binary_tree_is_root - Check if a node is root or not
* @node: A node to check
*
* Return: 1 if a node is leaf, 0 otherwise
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	return (0);
}
