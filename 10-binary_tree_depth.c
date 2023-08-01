#include "binary_trees.h"

/**
 * binary_tree_depth - get the depth of a node
 * @tree: the node to get the depth
 *
 * Return: returns the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
		height++;
	height += binary_tree_depth(tree->parent);

	return (height);
}
