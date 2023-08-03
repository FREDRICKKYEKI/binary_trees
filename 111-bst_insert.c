#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary tree
 * @tree: the tree to work with
 * @value: the value to insert
 *
 * Return: returns the added node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp;

	if (tree == NULL)
		return (NULL);
	temp = *tree;
	if (temp == NULL)
	{
		new = binary_tree_node(temp, value);
		*tree = new;
		return (new);
	}
	if (value < temp->n) /* left side */
	{
		if (temp->left != NULL)
			return (bst_insert(&temp->left, value));

		new = binary_tree_node(temp, value);
		if (new == NULL)
			return (NULL);
		return (temp->left = new);
	}
	if (value > temp->n) /* right side */
	{
		if (temp->right != NULL)
			return (bst_insert(&temp->right, value));

		new = binary_tree_node(temp, value);
		if (new == NULL)
			return (NULL);
		return (temp->right = new);
	}

	return (NULL);
}
