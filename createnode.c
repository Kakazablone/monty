#include "monty.h"

/**
*
*
*
*/

stack_t *createnode(int num)
{
	stack_t *node = NULL;
	node = malloc(sizeof(stack_t);
	node->n = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
