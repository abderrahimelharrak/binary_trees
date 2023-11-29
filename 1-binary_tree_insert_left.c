#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of another node
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 * Return: success
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau;

	if (parent == NULL)
		return (NULL);

	nouveau = binary_tree_node(parent, value);
	if (nouveau == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		nouveau->left = parent->left;
		parent->left->parent = nouveau;
	}
	parent->left = nouveau;

	return (nouveau);
}
