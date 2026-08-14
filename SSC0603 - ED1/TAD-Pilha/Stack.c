#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct stack {
    int maxSize;
    int currentSize;
    Data* data;
};

Stack* stack_create(int maxSize) {
    if (maxSize <= 0) return NULL;

    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->data = (Data*) malloc(sizeof(Data) * maxSize);
    if (s->data == NULL) {
        free(s);
        return NULL;
    };

    s->currentSize = 0;
    s->maxSize = maxSize;
    return s;
}

int stack_isFull(Stack *s) {
    return s->currentSize == s->maxSize;
}

int stack_isEmpty(Stack* s) {
    return s->currentSize == 0;
}

void stack_destroy(Stack* s) {
    if (s != NULL) {
        free(s->data);
        free(s);
    }
}

int stack_push(Stack* s, Data d) {
    if (stack_isFull(s)) return 0;
    s->data[s->currentSize] = d;
    s->currentSize++;
    return 1;
}

int stack_peek(Stack* s, Data* d) {
    if (stack_isEmpty(s)) return 0;
    *d = s->data[s->currentSize-1];
    return 1;
}

int stack_pop(Stack* s, Data* d) {
    if (stack_isEmpty(s)) return 0;
    *d = s->data[s->currentSize-1];
    s->currentSize--;
    return 1;
}

void stack_print(Stack* s) {
    if (stack_isEmpty(s)) return;
    printf("[");
    for (int i=0; i<s->currentSize; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
