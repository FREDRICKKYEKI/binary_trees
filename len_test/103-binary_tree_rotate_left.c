#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree
 * @tree: the tree to rotate
 *
 * Return: returns the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *temp_parent;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (tree);

	temp_parent = tree->parent;
	tree->parent = tree->right;
	temp = tree->right->left;
	tree->right->left = tree;
	tree = tree->right;
	if (temp != NULL)
		temp->parent = tree->left;
	tree->left->right = temp;
	tree->parent = temp_parent;

	return (tree);
}
