#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right totation on a binary tree
 * @tree: the tree to rotate
 *
 * Return: returns the address of the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *temp_parent;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);

	temp_parent = tree->parent;
	tree->parent = tree->left;
	temp = tree->left->right;
	tree->left->right = tree;
	tree = tree->left;
	if (temp != NULL)
		temp->parent = tree->right;
	tree->right->left = temp;
	tree->parent = temp_parent;

	return (tree);
}
