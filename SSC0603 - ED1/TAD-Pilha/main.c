#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAX_CAPACITY 10

int main(void) {
    char buffer[32];

    Stack* pilha = stack_create(MAX_CAPACITY);

    for (int i = 0; i < 5; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        int num = atoi(buffer);
        stack_push(pilha, num);
    }

    stack_print(pilha);

    stack_destroy(pilha);
    return 0;
}
