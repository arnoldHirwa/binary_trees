#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of 2 nodes
* @first: The first node
* @second: The second node
*
* Return: Lowest common ancestor, or null if not found
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t one;
	binary_tree_t two;
	binary_tree_t *currentOne;
	binary_tree_t *currentTwo;

	if (first == NULL || second == NULL)
		return (NULL);

	one = *first;
	two = *second;
	currentOne = &one;
	currentTwo = &two;

	while (currentOne->parent != NULL)
	{
		while (currentTwo->parent != NULL)
		{
			if (currentOne->parent == currentTwo->parent)
				return (currentOne->parent);
			currentTwo = currentTwo->parent;
		}
		currentOne = currentOne->parent;
	}
	return (NULL);
}
