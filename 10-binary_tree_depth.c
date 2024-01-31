#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a node in a tree
* @tree: Node whose depth is measured
*
* Return: The depth of the node
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t node;

	if (tree == NULL)
		return (0);

	node = *tree;
	while (node.parent != NULL)
	{
		node = *(node.parent);
		depth += 1;
	}
	return (depth);
}
