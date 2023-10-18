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
