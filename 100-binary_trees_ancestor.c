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
	binary_tree_t one = *first;
	binary_tree_t two = *second;
	binary_tree_t *currentOne = &one;
	binary_tree_t *currentTwo = &two;

	if (first == NULL || second == NULL)
		return (NULL);

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
