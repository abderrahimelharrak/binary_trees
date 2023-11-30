#ifndef STRUCT_H
#define STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * struct levelorder - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder;
