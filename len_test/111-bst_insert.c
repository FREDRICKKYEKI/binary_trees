#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, temp;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree)
	}

	temp = *tree;
	if (value < temp->n)
	{
		while (value < temp
	}
	else
	{}

	return (new);
}
