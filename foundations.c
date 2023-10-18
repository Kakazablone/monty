#include "monty.h"

/**
*
*
*
*
*/

void line_parse(char *buf, int line)
{
char *opcode = NULL, *opvalue = NULL, *delim = "\n ";

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
	}

	opcode = strtok(buf, delim);
	opvalue = strtok(NULL, delim);
	opcode_mapping(opcode, opvalue, line);

}

/**
*
*
*
*
*/

void opcode_mapping(char *opcode, char *opvalue, unsigned int line)
{
	int i = 0, flag;

	instruction_t opsmap[] = {
	{"push", push},
    {"pall", pall},
	{"pint", show_top},
	{"add", addition},
/*	{"swap", swap},*/
	{"pop", pop},
	{"nop", nop},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; opsmap[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opsmap[i].opcode) == 0)
		{
			execute_func(opsmap[i].f, opcode, opvalue, line);
			flag = 0;
		}
	}
	if (flag == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
}

/**
*
*
*
*/

void execute_func(op_func function, char *opcode, char *opvalue, unsigned int line)
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
 *
 *
 *
 *
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
