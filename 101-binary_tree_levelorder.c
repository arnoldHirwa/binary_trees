#include "binary_trees.h"

/*
*linked_list_s // binary_tree_s
*{
*	int n; // value of node
*	binary_tree_s *left; // next node
*	binary_tree_s *right; // null
*	binary_tree_s *parent; /// null
*} linked_list_t; // binary_tree_t
*
*/

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
	current->left = binary_tree_node(NULL, node->n);
	current->left->right = node;
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

	root = binary_tree_node(NULL, tree->n);
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
	binary_tree_delete(root);
}
