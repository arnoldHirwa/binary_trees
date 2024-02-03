#include "binary_trees.h"

/**
 * array_to_avl_support - builds an AVL tree from an array
 * @arr: pointer to the first element of the array to be converted
 * @l: left index
 * @r: right index
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl_support(int *arr, int l, int r, avl_t *parent)
{
	int index;
	avl_t *new_node = NULL;

	if (!arr || l > r)
		return (NULL);
	index = l + (r - l) / 2;
	new_node = binary_tree_node(parent, arr[index]);

	if (!new_node)
		return (NULL);
	new_node->left = array_to_avl_support(arr, l, index - 1, new_node);
	new_node->right = array_to_avl_support(arr, index + 1, r, new_node);
	return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	root = array_to_avl_support(array, 0, size - 1, root);
	return (root);
}
