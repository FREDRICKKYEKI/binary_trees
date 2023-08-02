#include "binary_trees.h"

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

	full = binary_tree_is_full(tree->left);
	full = binary_tree_is_full(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		full = 1;
	else if (tree->left != NULL && tree->right != NULL && full != 0)
		full = 1;
	else
		full = 0;

	return (full);
}