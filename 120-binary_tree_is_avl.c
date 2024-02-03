#include "binary_trees.h"

/**
* binary_traverse - A function which traverse a binary tree in inorder
* @tree: The head ot the tree
* @min: The minimum value a node can have
* @max: The maximum value a node can have
*
* Return: 1 success, 0 otherwise
*/

int binary_traverse(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_traverse(tree->left, min, tree->n - 1)
		&& binary_traverse(tree->right, tree->n + 1, max));
}

/**
* is_bst - Finds a whether a tree is a valid BST
* @tree: A top node of the tree
*
* Return: 1 if it is valid, 0 otherwise
*/

int is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_traverse((binary_tree_t *)tree, -2147483648, 2147483647));
}

/**
 * tree_height - gets the height of a binary tree
 * @tree: root node to draw height from for tree
 * Return: size_t representing height, 0 on failure or NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	left_size += 1 + tree_height(tree->left);
	right_size += 1 + tree_height(tree->right);
	if (left_size > right_size)
		return (left_size);

	return (right_size);
}

/**
 * is_avl - check if a tree is avl
* @tree: A tree to check
*
* Return: 1 if it is valid AVL, 0 otherwise
*/

int is_avl(const binary_tree_t *tree)
{
	int left = 0, right = 0, diff = 1;

	if (tree == NULL)
		return (1);

	if (tree->left)
		left = tree_height(tree->left);
	if (tree->right)
		right = tree_height(tree->right);

	if (left - right > 1 || left - right < -1)
		diff = 0;
	else
		diff = 1;

	return (diff && is_avl(tree->right)
			&& is_avl(tree->left));
}

/**
* binary_tree_is_avl - check if a tree is avl
* @tree: A tree to check
*
* Return: 1 if it is valid AVL, 0 otherwise
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree) && is_bst(tree));
}
