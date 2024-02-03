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
* @max_val: the maximum value a node should have
* Return: 1 if it is complete, 0 otherwise
*/
int is_complete(binary_tree_t *tree, int index, int nodes, int max_val)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes || tree->n > max_val)
		return (0);
	return (is_complete(tree->left,  2 * index + 1, nodes, tree->n - 1) &&
			is_complete(tree->right, 2 * index + 2, nodes, tree->n - 1));
}

/**
* binary_tree_is_heap - Finds whether a tree is complete or not
* @tree: root node
* Return: 1 if it is complete, 0 otherwise.
*/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes;

	if (tree == NULL)
		return (0);

	nodes = nbr_of_nodes((binary_tree_t *)tree);

	return (is_complete((binary_tree_t *)tree, 0, nodes, tree->n));
}
