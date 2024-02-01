#include "binary_trees.h"

/**
* nbr_of_nodes - Calculates nbr of nodes of a tree
* @tree: A tree whose nodes we are going to count
*
* Return: number of nodes
*/

int nbr_of_nodes(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + nbr_of_nodes(tree->left) + nbr_of_nodes(tree->right));
}

/**
* is_complete - check if a tree is complete
* @tree: A tree to check
* @index: Index of tree
* @nodes: number of nodes of a tree
*
* Return: 1 if it is complete, 0 otherwise
*/
int is_complete(binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);
	return (is_complete(tree->left,  2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
* binary_tree_is_complete - Finds whether a tree is complete or not
* @tree: root node
* Return: 1 if it is complete, 0 otherwise.
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;

	if (tree == NULL)
		return (0);

	nodes = nbr_of_nodes((binary_tree_t *)tree);

	return (is_complete((binary_tree_t *)tree, 0, nodes));
}
