#include "binary_trees.h"
#include "struct.h"

/**
 * pops - Pops the head of a levelorder_queue_t queue.
 * @h: A double pointer to the head of the queue.
 */
void pops(levelorder **h)
{
	levelorder *temp;

	temp = (*h)->next;
	free(*h);
	*h = temp;
}

/**
 * cr_node - Creates a new levelorder_queue_t node.
 * @nod: The binary tree node for the new node to contain.
 * Return: success
 */
levelorder *cr_node(binary_tree_t *nod)
{
	levelorder *nouveau;

	nouveau = malloc(sizeof(levelorder));
	if (nouveau == NULL)
		return (NULL);

	nouveau->node = nod;
	nouveau->next = NULL;

	return (nouveau);
}

/**
 * free_q - Frees a levelorder queue.
 * @h: A pointer to the head of the queue.
 */
void free_q(levelorder *h)
{
	levelorder *temp;

	while (h != NULL)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}

/**
 * p_push - Runs a function on a given binary tree node and
 * @nod: The binary tree node to print and push.
 * @h: A double pointer to the head of the queue.
 * @t: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void p_push(binary_tree_t *nod, levelorder *h,
		levelorder **t, void (*func)(int))
{
	levelorder *nouveau;

	func(nod->n);
	if (nod->left != NULL)
	{
		nouveau = cr_node(nod->left);
		if (nouveau == NULL)
		{
			free_q(h);
			exit(1);
		}
		(*t)->next = nouveau;
		*t = nouveau;
	}
	if (nod->right != NULL)
	{
		nouveau = cr_node(nod->right);
		if (nouveau == NULL)
		{
			free_q(h);
			exit(1);
		}
		(*t)->next = nouveau;
		*t = nouveau;
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder *h, *t;

	if (tree == NULL || func == NULL)
		return;

	h = t = cr_node((binary_tree_t *)tree);
	if (h == NULL)
		return;

	while (h != NULL)
	{
		p_push(h->node, h, &t, func);
		pops(&h);
	}
}
