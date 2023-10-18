#include "monty.h"
#include <stdio.h>
#include <string.h>

stack_t *head = NULL;

/**
 *main - entry point
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 success
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char buffer[1024];
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, 1024, fp) != NULL)
	{
		line_parse(buffer, line);
		line++;
	}


	fclose(fp);
	freenodes();
	return (0);
}


/**
*freenodes - frees nodes
*Return: void
*/

void freenodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
