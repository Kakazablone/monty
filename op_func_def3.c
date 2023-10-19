#include "monty.h"

/**
*pchar - prints the char(ascii) value at the top of stack
*@stack: top of stack
*@line: line number
*/

void pchar(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
