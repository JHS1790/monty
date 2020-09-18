#ifndef LIZZIE
#define LIZZIE

/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *
 */
typedef struct global_s
{
	int *n;
	char **buffer;
	FILE **file;
} global_t;

/* Global Variables */
extern global_t *global_variables;

/* Project Prototypes */
void push_monty(stack_t **stack, unsigned int line_number);
void pall_monty(stack_t **stack, unsigned int line_number);
void pint_monty(stack_t **stack, unsigned int line_number);
void pop_monty(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void add_monty(stack_t **stack, unsigned int line_number);
void nop_monty(stack_t **stack, unsigned int line_number);
void mul_monty(stack_t **stack, unsigned int line_number); 
void sub_monty(stack_t **stack, unsigned int line_number); 
void div_monty(stack_t **stack, unsigned int line_number); 

/* Non-Project Prototypes */
int check_opcode(stack_t **stack, unsigned int line_number
, char *token_opcode, char *token_int);
int check_token_int(char *token_int);
void free_monty_stack(stack_t **stack);
void error_monty(int errorcode, stack_t **stack, char *file);
void insert_int(char *token_int, int *n); 
#endif /* LIZZIE */
