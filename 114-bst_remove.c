#include "binary_trees.h"

/**
* minValue - Finds the smallest value of a tree
* @tree: head of the tree
*
* Return: Node to the smallest value
*/

bst_t *minValue(bst_t *tree)
{
	bst_t *current = tree;

	if (current == NULL)
		return (NULL);
	if (current->left)
		current = current->left;

	return (current);
}

/**
* bst_remove - search a value in bst
* @root: the root of the tree
* @value: the value to remove from tree
*
* Return: The root of the tree
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL, *successor = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		successor = minValue(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
