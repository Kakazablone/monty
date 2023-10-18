#include "monty.h"

/**
*
*
*
*
*/

void line_parse(char *buf)
{
char *opcode = NULL, *opvalue = NULL, *delim = "\n ";

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
	}

	opcode = strtok(buf, delim);
	opvalue = strtok(NULL, delim);
	printf("%s\n%s\n", opcode, opvalue);

}

/**
*
*
*
*
*/

int opcode_mapping(char *opcode, char *opvalue, unsigned int line)
{
	int i = 0;

	instruction_t opsmap[] = {
	{"push", push()},
	{"pall", pall()},
	{"pint", pint()},
	{"add", add()},
	{"swap", swap()},
	{"pop", pop()},
	{"nop", nop()},
	{NULL, NULL}
	}; --track-origins=yes

	if (opcode[0] == '#')
		return;

	for (i = 0; i <= 7; i++)
	{
		if (strcmp(opcode, opsmap[i].opcode) == 0)
			opsmap.f(opsmap[i], line);
	}
}
