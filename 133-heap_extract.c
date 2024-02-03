#include "binary_trees.h"

/**
* balance - balance a tree in heap format
* @tree: a pointer to the tree to balance
*/

void balance(heap_t *tree)
{
	int tmp;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return;
	if (tree->left)
	{
		balance(tree->left);
		if (tree->n < tree->left->n)
		{
			tmp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = tmp;
		}
	}
	if (tree->right)
	{
		balance(tree->right);
		if (tree->n < tree->right->n)
		{
			tmp = tree->n;
			tree->n = tree->right->n;
			tree->right->n = tmp;
		}
	}
}

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
* traverse - A function which traverse a tree up to the last node
* @tree: A tree to traverse
* @index: index of a node
* @nodes: number of nodes in a tree
* @last: pointer to the last node
* Return: None
*/

void traverse(heap_t *tree, int index, int nodes, heap_t **last)
{
	if (tree == NULL || *last)
		return;

	if (index == nodes - 1)
	{
		*last = tree;
	} else
	{
		traverse(tree->left, 2 * index + 1, nodes, last);
		if (!*last)
			traverse(tree->right, 2 * index + 2, nodes, last);
	}
}

/**
* heap_extract - Remove the root node
* @root: root of the tree
*
* Return: value stored in the root node, 0 on fail
*/

int heap_extract(heap_t **root)
{
	heap_t *last = NULL;
	int nodes;
	int replace;

	if (root == NULL || *root == NULL)
		return (0);

	replace = (*root)->n;
	nodes = nbr_of_nodes(*root);

	traverse(*root, 0, nodes, &last);
	if (last)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;

		(*root)->n = last->n;
		free(last);
	} else
	{
		return (0);
	}

	balance(*root);
	return (replace);
}
