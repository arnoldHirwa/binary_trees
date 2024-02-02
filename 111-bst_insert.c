#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *current = NULL, *parent = NULL;

	if (!tree)
		return (NULL);

	current = *tree;
	while (current)
	{
		parent = current;
		if (current->n == value)
			return (NULL);
		if (current->n > value)
			current = current->left;
		else
			current = current->right;
	}
	new_node = binary_tree_node(NULL, value);

	if (new_node)
		new_node->parent = parent;
	if (!parent)
		*tree = new_node;
	else if (parent->n > value)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
