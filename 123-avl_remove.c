#include "binary_trees.h"

/**
 * balance_avl - rebalances an AVL tree
 * @node: pointer to the node to rebalance
 * Return: pointer to the root node of the tree after rebalancing
 */
avl_t *balance_avl(avl_t *node)
{
	int balance_factor;

	if (!node)
		return (NULL);
	balance_factor = binary_tree_balance(node);
	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}

/**
* minValue - Finds the smallest value of a tree
* @tree: head of the tree
*
* Return: Node to the smallest value
*/

avl_t *minValue(avl_t *tree)
{
	avl_t *current = tree;

	if (current == NULL)
		return (NULL);
	if (current->left)
		current = current->left;

	return (current);
}

/**
* avl_remove - search a value in avl
* @root: the root of the tree
* @value: the value to remove from tree
*
* Return: The root of the tree
*/

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL, *successor = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (balance_avl(temp));
		}
		successor = minValue(root->right);
		root->n = successor->n;
		root->right = avl_remove(root->right, successor->n);
	}
	return (balance_avl(root));
}
