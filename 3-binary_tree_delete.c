#include "binary_trees.h"

/**
* delete_node - A recursive function for deleting node
* @node: A node to be deleted
* @left: Direction of the child with respect to the parent
*
* Return: None
*/
void delete_node(binary_tree_t *node, bool left)
{
	binary_tree_t *parent;

	if (node->left != NULL)
	{
		delete_node(node->left, true);
	}
	if (node->right != NULL)
	{
		delete_node(node->right, false);
	}

	parent = node->parent;
	if (parent != NULL)
	{
		if (left)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	node->parent = NULL;
	free(node);
}

/**
* binary_tree_delete - Deletes a tree
* @tree: A tree to be deleted
*
* Return: None
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	delete_node(tree, true);
}
