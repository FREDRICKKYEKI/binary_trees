#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1
 * child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number
 * of nodes
 *
 * Return: number of nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t n = 0, nl = 0, nr = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		n = 0;
	else
		n = 1;

	nl = binary_tree_nodes(tree->left);
	nr = binary_tree_nodes(tree->right);

	return (n + nl + nr);
}
