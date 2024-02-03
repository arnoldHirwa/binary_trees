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
* binary_search - Computes whether a tree is perfect or not
* @tree: Head of the binary tree
* @height: height of the leaf node
* @first: Determine whether you are going to
*	calculate height for the first time
* Return: 1 if the tree can't be perfect
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
* binary_tree_is_perfect_2 - Computes whether a tree is perfect or not
* @tree: Head of the binary tree
*
* Return: 1 if the tree can be perfect, 0 otherwise
*/

int binary_tree_is_perfect_2(const binary_tree_t *tree)
{

	int count;
	int height = 0;
	bool first = true;

	if (tree == NULL)
		return (0);

	count = binary_search(tree, &height, &first);

	return (count == 0 ? 1 : 0);
}

/**
* heap_balance - balance a tree in heap format
* @tree: a pointer to the tree to balance
* @container: A double pointer which keep track of created node
*/

void heap_balance(heap_t *tree, heap_t **container)
{
	int tmp;
	heap_t *node = *container;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return;
	if (tree->left)
	{
		heap_balance(tree->left, container);
		if (tree->n < tree->left->n)
		{
			if (tree->n == node->n)
				*container = tree->left;
			if (tree->left->n == node->n)
				*container = tree;
			tmp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = tmp;
		}
	}
	if (tree->right)
	{
		heap_balance(tree->right, container);
		if (tree->n < tree->right->n)
		{
			if (tree->n == node->n)
				*container = tree->right;
			if (tree->right->n == node->n)
				*container = tree;
			tmp = tree->n;
			tree->n = tree->right->n;
			tree->right->n = tmp;
		}
	}
}

/**
* insert - Inserts a value in an heap Tree
* @tree: Pointer to the root node of the heap tree for inserting the value
* @node: Node to be inserted
* @container: A double pointer which keep track of created node
* Return: Pointer to the created node, or NULL on failure
*/
heap_t *insert(heap_t *tree, heap_t *node, heap_t **container)
{
	if (!node)
		return (NULL);
	if (tree == NULL)
		return (node);
	if (binary_tree_is_perfect_2(tree) || !binary_tree_is_perfect_2(tree->left))
	{
		tree->left = insert(tree->left, node, container);
		tree->left->parent = tree;
	} else
	{
		tree->right = insert(tree->right, node, container);
		tree->right->parent = tree;
	}
	heap_balance(tree, container);
	return (tree);
}

/**
* heap_insert - Inserts a value in an heap Tree
*
* @tree: Pointer to the root node of the heap tree for inserting the value
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **tree, int value)
{
	heap_t *new_node = NULL, **container = &new_node;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	*tree = insert(*tree, new_node, container);
	return (*container);
}
