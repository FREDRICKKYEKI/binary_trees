#include "binary_trees.h"

/**
 * bin_nodes - Function that returns the number of nodes in tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: number of nodes
*/
size_t bin_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + bin_nodes(tree->left) + bin_nodes(tree->right));
}

/**
 * power - finds input to the power of given exponential
 *
 * @num: number to exponentiate (base)
 * @exp: exponent
 *
 * Return: Result
*/
size_t power(int num, int exp)
{
	int i, ans = num;

	for (i = 1; i < exp; i++)
		ans = ans * num;

	return (ans);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree
 * is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, max_level, max_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	max_level = height + 1;

	max_nodes = power(2, max_level) - 1;

	if (bin_nodes(tree) == max_nodes)
		return (1);

	return (0);
}
