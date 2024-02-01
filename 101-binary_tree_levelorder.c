#include "binary_trees.h"

/**
* delete_head_node - deletes a listint node at index
*
* @head: head of list
*
* Return: 1 if successful, -1 otherwise
*/
int delete_head_node(listint_t **head)
{
	listint_t *ptr = NULL;

	if (head == NULL || *head == NULL)
		return (-1);

	ptr = *head;
	*head = (*head)->next;
	free(ptr);
	return (1);
}
/**
* add_node_end - adds a listint node to the end of a list
*
* @head: head of list
* @node: value to give new node
*
* Return: address of new node
*/
listint_t *add_node_end(listint_t **head, binary_tree_t *node)
{
	listint_t *ptr, *end;

	if (head == NULL)
		return (NULL);
	end = *head;
	if (end != NULL)
		while (end->next != NULL)
			end = end->next;

	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);

	ptr->node = node;
	if (*head == NULL)
		*head = ptr;
	else
		end->next = ptr;
	ptr->next = NULL;
	return (ptr);
}
/**
* binary_tree_levelorder - Traverse a tree in levelorder
* @tree: Head of the binary tree
* @func: A function to call with the value of each node
* Return: None
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current_t;
	listint_t *que = NULL;

	if (tree == NULL || func == NULL)
		return;

	add_node_end(&que, (binary_tree_t *)tree);

	while (que != NULL)
	{
		current_t = que->node;
		func(current_t->n);
		if (current_t->left != NULL)
		{
			add_node_end(&que, current_t->left);
		}
		if (current_t->right != NULL)
		{
			add_node_end(&que, current_t->right);
		}
		delete_head_node(&que);
	}
}
