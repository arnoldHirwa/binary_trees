#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of 2 nodes
* @first: The first node
* @second: The second node
*
* Return: Lowest common ancestor, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	const binary_tree_t *currentOne;
	const binary_tree_t *currentTwo;

	if (first == NULL || second == NULL)
		return (NULL);

	currentOne = first;
	currentTwo = second;

	while (currentOne != currentTwo)
	{
		currentOne = (currentOne == NULL) ? second : currentOne->parent;
		currentTwo = (currentTwo == NULL) ? first : currentTwo->parent;
	}

	return ((binary_tree_t *)currentOne);
}
