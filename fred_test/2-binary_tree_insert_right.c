#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the
 * right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node or NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->right = parent->right;
	new->n = value;
	new->parent = parent;
	new->left = NULL;

	if (parent->right != NULL)
		parent->right->parent = new;

	parent->right = new;

	return (new);
}
