#include "monty.h"

/**
*line_parse - parse through individual lines from stream
*@buf: line from file
*@line: line number
*Return: Void
*/

void line_parse(char *buf, int line)
{
char *opcode = NULL, *opvalue = NULL, *delim = " \n";

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buf, delim);
	opvalue = strtok(NULL, delim);
	opcode_mapping(opcode, opvalue, line);

}

/**
*opcode_mapping - links an 'opcode' to corresponding function
*@opcode: operation code
*@opvalue: operation argument
*@line: line umber
*Return: Void
*/

void opcode_mapping(char *opcode, char *opvalue, unsigned int line)
{
	int i = 0, flag;

	instruction_t opsmap[] = {
	{"push", push},
	{"pall", pall},
	{"pint", show_top},
	{"add", addition},
	{"swap", swap},
	{"pop", pop},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; opsmap[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opsmap[i].opcode) == 0)
		{
			execute(opsmap[i].f, opcode, opvalue, line);
			flag = 0;
		}
	}
	if (flag == 1)
		fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
}

/**
*execute - executes an operation based on an opcode
*@function: function to be executed
*@opcode: operation code
*@opvalue: operation argument
*@line: line number in file
*
*/

void execute(op_func function, char *opcode, char *opvalue, unsigned int line)
{
	stack_t *node;
	int i, flag;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (opvalue != NULL && opvalue[0] == '-')
		{
			opvalue = opvalue + 1;
			flag = -1;
		}
		if (opvalue == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", line);
		for (i = 0; opvalue[i] != '\0'; i++)
		{
			if (isdigit(opvalue[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", line);
		}
		node = newnode(atoi(opvalue) * flag);
	    function(&node, line);
	}
	else
		function(&head, line);
}

/**
 *newnode - creates a new doubly linked list node
 *@n: data to be inserted into node
 *Return: pointer to new node
 */

stack_t *newnode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fprintf(stderr, "Error: Malloc failed\n");
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
*mod - modulo's top elem value from second to element val
*@stack: address of pointer to firsr stack element
*@line: line number
*
*/

void mod(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if ((*stack)->prev->n != 0)
		result = (*stack)->n % (*stack)->prev->n;
	else
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
