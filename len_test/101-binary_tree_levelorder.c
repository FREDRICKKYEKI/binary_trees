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
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left >= right)
		return (left + 1);

	return (right + 1);
}

/**
 * levelorder_recursive - performs an operation in a levelorder recursive way
 * @tree: the tree to traverse
 * @level: the current level of items in tree
 * @func: the function to perform an operation with
 */
void levelorder_recursive(const binary_tree_t *tree, size_t level,
			  void (*func)(int))
{
	if (tree == NULL)
		return;

	/* if at the top of a subtree */
	if (level == 0)
		func(tree->n);

	else
	{
		/* decrease level by one and go down the tree */
		levelorder_recursive(tree->left, level - 1, func);
		levelorder_recursive(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints a binary tree in a level order manner
 * @tree: the tree to print
 * @func: function pointer to the function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i < height; i++)
		levelorder_recursive(tree, i, func);
}
