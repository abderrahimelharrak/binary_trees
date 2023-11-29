#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child of another node
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 * Return: success
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau;

	if (parent == NULL)
		return (NULL);

	nouveau = binary_tree_node(parent, value);
	if (nouveau == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		nouveau->right = parent->right;
		parent->right->parent = nouveau;
	}
	parent->right = nouveau;

	return (nouveau);
}
