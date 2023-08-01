#include "binary_trees.h"


/**
 * binary_tree_leaves - function that counts the leaves in a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to count
 * the number of leaves
 *
 * Return: number of leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/** A NULL pointer is not a leaf */

	size_t l = 0, lr = 0, ll = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		l = 1;

	ll = binary_tree_leaves(tree->left);
	lr = binary_tree_leaves(tree->right);

	return (l + ll + lr);
}
