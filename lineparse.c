#include "monty.h"

/**
*
*
*
*
*/

void line_parse(char *buf, unsigned int line)
{
char *opcode = NULL, *opvalue = NULL, *delim = "\n ";
stack_t *newnode = NULL;

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
	}

	opcode = strtok(buf, delim);
	opvalue = strtok(NULL, delim);
	atoi(opvalue);
	/*printf("%s\n%s\n", opcode, opvalue);*/


	opcodecode_mapping(opcode, stck, line);

}

/**
*
*
*
*
*/

int opcode_mapping(char *opcode, stack_t stck, unsigned int line)
{
	int i = 0;

	instruction_t opsmap[] = {
	{"push", push},
	{"pall", pall},
/*	{"pint", pint},
	{"add", adD},
	{"swap", swap},
	{"pop", pop},
	{"nop", nop},
	{NULL, NULL}*/
	};

	if (opcode[0] == '#')
		return (0);

	for (i = 0; i <= 7; i++)
	{
		if (strcmp(opcode, opsmap[i].opcode) == 0)
			opsmap[i].f(&stck, line);
	}
}

/**
*
*
*
*/

void push(stack_t **stack, unsigned int line)
{
stack_t *current = *stack, *newnode = NULL;

newnode = createnode();
if (stack == NULL)
	stack = ;
else
{
	stack->next = NULL;
	stack->prev = 


}

/**
*
*
*
*/

void pall(stack_t **stack, unsigned int line)
{
stack_t *stck = NULL;

if (stck == NULL)
	return;
else
{
	while (stck != NULL)
	{
		printf("%d\n", stck->n);
		stck = stck->next;
	}
}
}
