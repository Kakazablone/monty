#include "monty.h"

/**
 * addition - sums the top 2 elements on stack
 *
 * @stack: Pointer to head
 * @line: opcode line number
 */

void addition(stack_t **stack, unsigned int line)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 *swap - swap the top two elements in the stack
 *@stack: address of pointer to first stack element
 *@line: line number
 *
 */

void swap(stack_t **stack, unsigned int line)
{
	stack_t *top, *secondtop;
	(void)line;
	if (*stack == NULL || stack ==  NULL)
		return;

	top = *stack;
	secondtop = top->next;

	top->next = secondtop->next;
	if (secondtop->next != NULL)
		secondtop->next->prev = top;

	secondtop->prev = top->prev;
	if (top->prev != NULL)
		top->prev->next = secondtop;

	top->prev = secondtop;
	secondtop->next = top;

	*stack = secondtop;
}
