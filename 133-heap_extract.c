#include "binary_trees.h"


/**
* sift_down - balance a tree in heap format
* @root: a pointer to the tree to balance
*/

void sift_down(heap_t *root)
{
	heap_t *largest = root, *current = NULL;
	int temp;

	while (largest != current)
	{
		current = largest;
		if (current->left && current->left->n > current->n)
			largest = current->left;
		if (current->right && current->right->n > largest->n)
			largest = current->right;
		temp = current->n;
		current->n = largest->n;
		largest->n = temp;
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
 * get_last_node - Gets the last node of a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap
 * @index: Index of the current node in the binary representation of the size
 * @size: Size of the Heap
 *
 * Return: Pointer to the last node of the Heap
 */
heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
	heap_t *node = root;

	if (!root || index >= size)
		return (NULL);
	if (index == size - 1)
		return (node);
	node = get_last_node(root->left, 2 * index + 1, size);
	if (node)
		return (node);
	return (get_last_node(root->right, 2 * index + 2, size));
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
	last = get_last_node(*root, 0, nodes);
	(*root)->n = last->n;
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	} else
		*root = NULL;
	free(last);

	sift_down(*root);
	return (replace);
}
