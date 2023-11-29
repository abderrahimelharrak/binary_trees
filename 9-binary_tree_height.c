#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: success
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x = 0, y = 0;

		if (tree->right)
			y = binary_tree_height(tree->right) + 1;
		else
			y = 0;

		if (tree->left)
			x = binary_tree_height(tree->left) + 1;
		else
			x = 0;

		return ((x > y) ? x : y);
	}
	return (0);
}
