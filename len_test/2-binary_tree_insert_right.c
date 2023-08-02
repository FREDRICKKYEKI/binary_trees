#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node to the right of specified node
 * @parent: the parent node
 * @value: value of the node to insert
 *
 * Return: returns the address of inserted node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *new;

	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		new = binary_tree_node(parent, value);
		parent->right = new;
	}
	else
	{
		temp = parent->right;
		new = binary_tree_node(parent, value);
		parent->right = new;
		temp->parent = new;
		new->right = temp;
	}

	return (new);
}
