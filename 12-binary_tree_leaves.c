#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 * Return: success
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t x = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			x = x + 1;
		x = x + binary_tree_leaves(tree->right);
		x = x + binary_tree_leaves(tree->left);
	}
	return (x);
}
