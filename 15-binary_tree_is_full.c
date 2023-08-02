#include "binary_trees.h"

/**
 * recursive_full - implements the recursive full
 * @tree: the tree to check
 *
 * Return: returns 1 if full, 0 otherwise
 */
int recursive_full(const binary_tree_t *tree)
{
	int full = 1, full_r = 1, full_l = 1;

	if (tree == NULL)
		return (1);

	full_l = binary_tree_is_full(tree->left);
	full_r = binary_tree_is_full(tree->right);

	if (full_l == 0 || full_r == 0)
		full = 0;

	if (tree->left == NULL && tree->right == NULL)
		full = 1;
	else if (tree->left != NULL && tree->right != NULL && full != 0)
		full = 1;
	else
		full = 0;

	return (full);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: the tree to check
 *
 * Return: returns 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (tree == NULL)
		return (0);

	full = recursive_full(tree);

	return (full);
}
