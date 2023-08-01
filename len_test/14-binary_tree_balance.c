#include "binary_trees.h"

/**
 * binary_tree_height - finds the height of a binary tree
 * @tree: the tree to get the height
 *
 * Return: returns the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, temp_height;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		height++;
	temp_height = binary_tree_height(tree->left);
	/* check max height items on left side */
	height = height > temp_height
		? height
		: height + temp_height;

	temp_height = binary_tree_height(tree->right);
	/* check max height items on right side */
	height = height > temp_height
		? height
		: height + temp_height;

	return (height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: the tree to get the balance factor
 *
 * Return: returns the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = binary_tree_height(tree->left) + 1;
	else if (tree->left == NULL)
		left = 0;

	if (tree->right != NULL)
		right = binary_tree_height(tree->right) + 1;
	else if (tree->right == NULL)
		right = 0;

	return (left - right);
}
