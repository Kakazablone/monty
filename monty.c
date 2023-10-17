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
char *buffer = NULL, *read = NULL;
int line = 1, len = 1024;

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
	while (read != NULL)
	{
		buffer = malloc(1024);
		read = fgets(buffer, len, fp);
		line_parse(buffer);
		line++;
		free(buffer);
	}


fclose(fp);
return (0);
}
