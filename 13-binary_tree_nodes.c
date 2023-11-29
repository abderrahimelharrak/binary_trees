#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 * Return: success
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t y = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			y = y + 1;
		y = y + binary_tree_nodes(tree->right);
		y = y + binary_tree_nodes(tree->left);
	}
	return (y);
}
