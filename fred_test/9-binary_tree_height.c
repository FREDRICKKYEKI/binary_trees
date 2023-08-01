#include "binary_trees.h"
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
	size_t h, hl, hr;

	if (tree == NULL)
		return (0);

	/*Base case for recursion*/
	if (tree->right == NULL && tree->left == NULL)
		return (0);

	hl = binary_tree_height(tree->left);
	hr = binary_tree_height(tree->right);

	if (hl > hr)
		h = hl;
	else
		h = hr;

	return (1 + h);
}
