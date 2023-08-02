#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: the node to find a sibling
 *
 * Return: returns the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent, *sibling;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->left == node)
		sibling = parent->right;
	else
		sibling = parent->left;

	return (sibling);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node to find the uncle
 *
 * Return: returns the uncle node, NULL on failure
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL)
		return (NULL);

	uncle = binary_tree_sibling(node->parent);

	return (uncle);
}
