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
char buffer[1024];
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
	
    while (fgets(buffer, 1024, fp) != NULL)
    {
        line_parse(buffer);
        line++;
    }


fclose(fp);
return (0);
}
