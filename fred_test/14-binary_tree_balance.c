#include "binary_trees.h"


/**
 * rec_height - recursively calculate height
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
*/
size_t rec_height(const binary_tree_t *tree)
{
	size_t h = 0, hl = 0, hr = 0;

	if (tree == NULL)
		return (0);

	hl = rec_height(tree->left);
	hr = rec_height(tree->right);

	if (hl > hr)
		h = hl;
	else
		h = hr;

	return (1 + h);
}

/**
 * bt_height - function that measures the height of a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
*/
size_t bt_height(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (-1);

	h = rec_height(tree);

	return (h - 1);
}

/**
 * binary_tree_balance - function that measures the balance factor
 * of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance
 * factor
 *
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bt_height(tree->left) - bt_height(tree->right));

}
