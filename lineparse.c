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
	/*printf("%s %s\n", opcode, opvalue);*/

}
