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
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
*pstr - prints string of ascii values in stack starting from top
*@stack: top of stack
*@line: line number
*
*/

void pstr(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	(void)line;

	if (stack == NULL || *stack == NULL)
		putchar('\n');

	while(temp != NULL || (*stack)->n > 0 || (*stack)->n < 128)
	{
		printf("%c", (*stack)->n);
		temp = temp->next;
	}
	putchar('\n');
}
