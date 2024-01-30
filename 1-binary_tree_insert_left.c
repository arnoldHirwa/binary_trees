#include "binary_trees.h"

/**
* binary_tree_insert_left - A function for inserting a node on the left
* @parent: A parent of the node
* @value: A value to the assigned to the node
*
* Return: A new ceated node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));
	binary_tree_t *old;

	if (new == NULL || parent == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = new;
		return (new);
	}
	old = parent->left;
	old->parent = new;
	parent->left = new;
	new->left = old;

	return (new);
}
