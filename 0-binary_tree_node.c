#include "binary_trees.h"

/**
* binary_tree_node - A function for creating new node
* @parent: A parent of the node
* @value: Value to be put in the node.
*
* Return: A new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL)
	{
		return (new);
	}

	new->parent = parent;

	return (new);
}
