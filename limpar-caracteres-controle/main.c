#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[50];

int i;

int main()
{
    fflush(stdin);

    fgets(input, sizeof(input), stdin);

    for(i=0; input[i] != '\0'; i++) {
        if(iscntrl( (unsigned char) input[i])) {
            input[i] = '\0';
            break;
        }

    }

    printf("%s\n" input);

    return 0;
}
