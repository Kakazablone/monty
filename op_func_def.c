#include "monty.h"
/**
 * push - pushes an element to the stack.
 *
 * @node: The node to containing the opvalue
 * @line: Line number of the operation
 */

void push(stack_t **node, unsigned int line)
{
	stack_t *temp;

	if (node == NULL || *node == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
    }
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}



/**
 * pall -  prints node in the stack.
 *
 * @stack: Pointer to head of the stack.
 * @line: line number of  the opcode.
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	(void) line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * nop - pass and do nothing.
 *
 * @stack: Pointer to the head
 * @line: opcode line number
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
  * pop - removes an element from the top of a stack
  * 
  *@stack: Pointer to head
  *@line: opcode line number
  */

void pop(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * show_top - prints the element at the top of the stack
 *
 * @stack: Pointer to head
 * @line: opcode line number
 */

void show_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
	printf("%d\n", (*stack)->n);
}
