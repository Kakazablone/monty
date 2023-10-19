#ifndef MONTY_H_
#define MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef void (*op_func)(stack_t **, unsigned int);


/* Foundations */
void line_parse(char *buf, int line);
extern stack_t *head;
void opcode_mapping(char *opcode, char *opvalue, unsigned int line);
void execute(op_func function, char *opcode, char *opvalue, unsigned int line);
void freenodes(void);
stack_t *newnode(int n);
/*int opcode_mapping(char *opcode, stack_t stck, unsigned int line);*/


/* Mandatory */
void pall(stack_t **stack, unsigned int line);
void push(stack_t **node, __attribute__((unused))unsigned int line);
void pop(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void show_top(stack_t **stack, unsigned int line);
void addition(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void divide(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);

/* Advanced */
#endif
