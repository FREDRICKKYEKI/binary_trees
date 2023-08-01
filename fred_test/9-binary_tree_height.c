#include "binary_trees.h"

/**
 * recursive_height - recursively calculate height
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
*/
size_t recursive_height(const binary_tree_t *tree)
{
	size_t h = 0, hl = 0, hr = 0;

	if (tree == NULL)
		return (0);

	hl = recursive_height(tree->left);
	hr = recursive_height(tree->right);

	if (hl > hr)
		h = hl;
	else
		h = hr;

	return (1 + h);
}

/**
 * binary_tree_height - function that measures the height of a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	h = recursive_height(tree);

	return (h - 1);
}
