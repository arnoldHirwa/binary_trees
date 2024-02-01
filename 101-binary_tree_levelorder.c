#include "binary_trees.h"

#include "binary_trees.h"

/**
* add_node - A function for creating new node
* @parent: A parent of the node
* @value: Value to be put in the node.
*
* Return: A new node
*/
binary_tree_t *add_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL)
	{
		return (new);
	}

	new->parent = parent;

	return (new);
}

/**
* add_node_end - Add a node to the end of tree
* @head: head of the node
* @node: node to add
* Return: None
*/
void add_node_end(binary_tree_t *head, binary_tree_t *node)
{
	binary_tree_t *current = NULL;

	if (head == NULL)
		return;

	current = head;
	while (current->left != NULL)
	{
		current = current->left;
	}
	current->left = add_node(NULL, node->n);
	current->left->right = node;
}

/**
* del_node - A recursive function for deleting node
* @node: A node to be deleted
* @left: Direction of the child with respect to the parent
*
* Return: None
*/
void del_node(binary_tree_t *node)
{
    binary_tree_t *current = NULL, *prev = NULL;
    if (node == NULL)
        return;
    while (current != NULL)
    {
        prev = current;
        current = current->left;
        prev->left = NULL;
        free(prev);
    }
}

/**
* binary_tree_levelorder - Traverse a tree in levelorder
* @tree: Head of the binary tree
* @func: A function to call with the value of each node
* Return: None
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *que, *root, *current_t;

	if (tree == NULL || func == NULL)
		return;

	root = add_node(NULL, tree->n);
	root->right = (binary_tree_t *)tree;
	que = root;

	for ( ; que != NULL; que = que->left)
	{
		current_t = que->right;
		if (current_t->left != NULL)
		{
			add_node_end(root, current_t->left);
		}
		if (current_t->right != NULL)
		{
			add_node_end(root, current_t->right);
		}
	}

	while (root != NULL)
	{
		func(root->n);
		root = root->left;
	}
	del_node(root);
}
