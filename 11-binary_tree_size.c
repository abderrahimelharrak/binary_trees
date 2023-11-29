#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 * Return: success
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t x = 0;

	if (tree)
	{
		x = x + 1;
		x = x + binary_tree_size(tree->left);
		x = x + binary_tree_size(tree->right);
	}
	return (x);
}
