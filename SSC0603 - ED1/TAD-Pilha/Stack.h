#ifndef STACK
#define STACK

typedef int Data;

typedef struct stack Stack;

Stack* stack_create(int maxSize);

int stack_isEmpty(Stack *s);
int stack_isFull(Stack *s);
int stack_push(Stack *s, Data d);
int stack_pop(Stack *s, Data* d);
int stack_peek(Stack *s, Data* d);
void stack_print(Stack *s);
void stack_destroy(Stack *s);

#endif
