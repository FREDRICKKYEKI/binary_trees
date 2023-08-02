#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node on the left of a parent node
 * @parent: the parent node
 * @value: the value to be inserted
 *
 * Return: returns the new node inserted
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *new;

	if (parent == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		new = binary_tree_node(parent, value);
		parent->left = new;
	}
	else
	{
		temp = parent->left;
		new = binary_tree_node(parent, value);
		parent->left = new;
		temp->parent = new;
		new->left = temp;
	}

	return (new);
}
