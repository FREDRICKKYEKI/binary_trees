#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * tree: the tree to count the nodes
 *
 * Return: returns the number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		nodes++;

	return (nodes);
}
