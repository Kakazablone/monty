#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
*
*
*
*
*/

int main(int argc, char *argv[])
{
FILE *fp = NULL;
char *buffer = NULL;
ssize_t read = 0, len = 0;
int line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while (read != -1)
	{
		read = getline(&buffer, &len, fp);
		line_parse(buffer);
		line++;
	}


free(buffer);
return (0);
}
