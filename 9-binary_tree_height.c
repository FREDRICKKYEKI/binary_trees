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
