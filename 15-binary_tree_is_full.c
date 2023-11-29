#include "binary_trees.h"

/* *
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: success
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - Checks if a binary tree is full recursively.
 * @tree: A pointer to the root node of the tree to check.
 * Return: success
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (tree->left != NULL && tree->right == NULL)
			return (0);
		if (tree->left == NULL && tree->right != NULL)
		       return (0);
		if (is_full_recursive(tree->left) == 0)
			return (0);
		if (is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}
