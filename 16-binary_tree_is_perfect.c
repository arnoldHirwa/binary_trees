#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a node in a tree
* @tree: Node whose depth is measured
*
* Return: The depth of the node
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t node;

	if (tree == NULL)
		return (0);

	node = *tree;
	while (node.parent != NULL)
	{
		node = *(node.parent);
		depth += 1;
	}
	return (depth);
}


/**
* binary_search - Computes whether a tree is full or not
* @tree: Head of the binary tree
* @height: height of the leaf node
* @first: Determine whether you are going to
*	calculate height for the first time
* Return: 1 if the tree can't be full
*/

int binary_search(const binary_tree_t *tree, int *height, bool *first)
{

	int count = 0, left = 0, right = 0, depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		count += 1;

	if (tree->right != NULL)
		count += 1;

	if (count == 0 || count == 2)
	{
		if (count == 2)
		{
			left = binary_search(tree->left, height, first);
			right = binary_search(tree->right, height, first);
		}
		if (count == 0)
		{
			depth = binary_tree_depth(tree);
			if (*first == true)
			{
				*height = depth;
				*first = false;
			} else
			{
				if (*height != depth)
				{
					return (1);
				}
			}
		}
		return (left + right);
	}
	return (1);
}

/**
* binary_tree_is_perfect - Computes whether a tree is full or not
* @tree: Head of the binary tree
*
* Return: 1 if the tree can't be full
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{

	int count;
	int height = 0;
	bool first = true;

	if (tree == NULL)
		return (0);

	count = binary_search(tree, &height, &first);

	return (count == 0 ? 1 : 0);
}
