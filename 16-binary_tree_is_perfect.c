#include "binary_trees.h"

/**
 * binary_tree_height - height of the binary tree
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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the tree to check
 *
 * Return: returns 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 1, right, left;

	if (tree == NULL)
		return (0);

	perfect = binary_tree_is_perfect(tree->left);
	perfect = binary_tree_is_perfect(tree->right);

	if (binary_tree_is_full(tree) == 0)
		perfect = 0;

	if (tree->left == NULL && tree->right == NULL)
		perfect = 1;

	if (tree->left != NULL)
		left = binary_tree_height(tree->left) + 1;
	else if (tree->left == NULL)
		left = 0;

	if (tree->right != NULL)
		right = binary_tree_height(tree->right) + 1;
	else if (tree->right == NULL)
		right = 0;

	if (right != left)
		perfect = 0;

	return (perfect);
}
