#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input[10], numTemp;

char temp[100];

int i, j;

int checkPrevDiff(int arr[], int index, int num);


int main()
{
    fflush(stdin);

    while (i < 10){

        fgets(temp, sizeof(temp), stdin);

        for(j=0; j < sizeof(temp); j++)
        if(temp[j] < 32){
            temp[j] = '\0';
            break;
        }

        numTemp = atoi(temp);

        if (checkPrevDiff(input, i, numTemp) || i == 0) {
            input[i] = numTemp;
            i++;
        }

    }

    for(i=0; i<10; i++) {
        printf("%d\n", input[i]);
    }


    return 0;
}

int checkPrevDiff(int arr[], int index, int num) {
    if(index == 0) {
        if (arr[index] == num) return 0;
        return 1;
    }

    if(arr[index] == num) return 0;

    return checkPrevDiff(arr, index -1, num);
}

