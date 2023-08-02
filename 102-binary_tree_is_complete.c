#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes in the tree
 * @tree: the tree to count nodes
 *
 * Return: returns the number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_complete - checks if  the tree is complete recursively
 * @tree: the tree to check
 * @index: the index of the current node
 * @nodes: the total number of nodes in the tree
 *
 * Return: returns 1 if tree is complete, otherwise 0
 */
int check_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, nodes) &&
		check_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the tree to check
 *
 * Return: returns 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes, index = 0;

	if (tree == NULL)
		return (0);

	num_nodes = count_nodes(tree);

	if (check_complete(tree, index, num_nodes))
		return (1);

	return (0);
}
