#include "binary_trees.h"

/**
 * recursive_full - function that performs recursion
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, otherwise 0
*/
int recursive_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/*If node is leaf*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*If node is parent*/
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	/*If the node has only one child*/
	return (0);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, otherwise 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full;

	if (tree == NULL)
		return (0);

	full = recursive_full(tree);

	return (full);
}
