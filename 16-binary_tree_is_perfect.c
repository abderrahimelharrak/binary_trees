#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
                size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: success
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * depth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 * Return: success
 */
size_t depth(const binary_tree_t *tree)
{
        if (tree->parent != NULL)
                return (1 + depth(tree->parent));
        else
                return (0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: success
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
        if (is_leaf(tree) == 1)
                return (tree);
        if (tree->left)
                return (get_leaf(tree->left));
        else
                return (get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: success
 */
int is_perfect_recursive(const binary_tree_t *tree,
                size_t leaf_depth, size_t level)
{
        if (is_leaf(tree))
                if (level == leaf_depth)
                        return (1);
                else
                        return (0);
        if (tree->left == NULL || tree->right == NULL)
                return (0);
        return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
                is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: success
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
