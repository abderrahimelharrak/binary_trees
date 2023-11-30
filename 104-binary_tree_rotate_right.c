#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer o the root node of the tree to rotate.
 * Return: success
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	x = tree->left;
	temp = x->right;
	x->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = x;
	x->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = x;
		else
			temp->right = x;
	}

	return (x);
}
