#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

char buff[16];

int mazeSize;

typedef struct {
    int x;
    int y;
} Cursor;

Cursor cursor;
int lastDir;

int iteration;

int getMazeSize();
void printIteration(int mazeSize, char maze[mazeSize][mazeSize], int iteration);
void fillMaze(int mazeSize, char maze[mazeSize][mazeSize]);
void iterate(int mazeSize, char maze[mazeSize][mazeSize], Cursor *c);

int main()
{
    do{
        printf("Please type the maze size [5 - 64]: ");

        mazeSize = getMazeSize();

    } while(mazeSize == -1);

    char maze[mazeSize][mazeSize];

    fillMaze(mazeSize, maze);

    iteration = 0;

    printIteration(mazeSize, maze, iteration);

    cursor.x = 1;
    cursor.y = 0;

    do {

        iterate(mazeSize, maze, &cursor);

        printIteration(mazeSize, maze, iteration);

        iteration++;

        #ifdef _WIN32
        Sleep(100);
        #else
        usleep(100000);
        #endif

    } while(cursor.x != mazeSize -2 || cursor.y != mazeSize -2);

    return 0;

}

int getMazeSize() {

    fflush(stdin);

    fgets(buff, sizeof(buff), stdin);

    for(int i = 0; i < sizeof(buff); i++) {
        if(buff[i] < 32) {
            buff[i]='\0';
            break;
        }
    }

    int num = atoi(buff);

    if(num < 5 || num > 64) num = -1;

    return num;

}

void printIteration(int mazeSize, char maze[mazeSize][mazeSize], int iteration){

    printf("\033[2J\033[H");

    printf("Iteration # %d \n", iteration);

    for(int i = 0; i < mazeSize; i++) {
        for(int j = 0; j < mazeSize; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

}

void fillMaze(int mazeSize, char maze[mazeSize][mazeSize]) {
    for(int i = 0; i < mazeSize; i++) {
            for(int j = 0; j < mazeSize; j++) {
                maze[i][j] = '#';
            }
        }

        maze[0][1] = 'E';
        maze[mazeSize -1][mazeSize-2] = 'S';

}


void iterate(int mazeSize, char maze[mazeSize][mazeSize], Cursor *c) {
    // 0 cima
    // 1 direita
    // 2 baixo
    // 3 esquerda
    int direction =  rand() % 4;
    lastDir = -1;

    if(direction == 0 && lastDir !=2) {
        if(c->y > 1) {
            c->y--;
            maze[c->y][c->x] = ' ';
        }
        lastDir = direction;
    }

    if(direction == 1 && lastDir !=3) {
        if(c->x < mazeSize - 2) {
            c->x++;
            maze[c->y][c->x] = ' ';
        }
        lastDir = direction;
    }

    if(direction == 2 && lastDir !=2) {
        if(c->y < mazeSize - 2) {
            c->y++;
            maze[c->y][c->x] = ' ';
        }
        lastDir = direction;
    }

    if(direction == 3 && lastDir !=2) {
        if(c->x > 1) {
            c->x--;
            maze[c->y][c->x] = ' ';
        }
        lastDir = direction;
    }



}
