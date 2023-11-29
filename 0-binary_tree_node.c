#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: success
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau;

	nouveau = malloc(sizeof(binary_tree_t));
	if (nouveau == NULL)
		return (NULL);

	nouveau->n = value;
	nouveau->parent = parent;
	nouveau->left = NULL;
	nouveau->right = NULL;

	return (nouveau);
}
