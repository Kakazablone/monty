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
    int ascii;
	(void)line;

	if (stack == NULL || *stack == NULL)
		putchar('\n');

	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}


/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
    (void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
