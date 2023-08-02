#include "binary_trees.h"

/**
 * binary_trees_ancestor - gets the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: returns a pointer to the lowest common ancestor
 * returns NULL if no ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *temp_l, *temp_r;

	if (first == NULL || second == NULL)
		return (NULL);

	temp_l = (binary_tree_t *)first;

	while (temp_l)
	{
		temp_r = (binary_tree_t *)second;
		while (temp_r)
		{
			if (temp_l == temp_r)
				return (temp_l);
			temp_r = temp_r->parent;
		}

		temp_l = temp_l->parent;
	}

	return (NULL);
}
