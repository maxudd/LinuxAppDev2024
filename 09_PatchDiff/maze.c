#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int maze_size = 6;
    int arr_size = (maze_size * 2) + 1;
    
    char **maze = calloc(sizeof(char *), arr_size);

    for (int i = 0; i < arr_size; i++){
        maze[i] = calloc(sizeof(char), arr_size + 1);
    }

    char border = '#';
    char skip = '.';

    for (int i = 0; i < arr_size; i++)
        for (int j = 0; j < arr_size; j++)
            maze[i][j] = border;

    int x = 1;
    int y = 1;
    maze[x][y] = skip;

    int flag = 0;
    while (!flag){
        int dir = rand() % 4;
        if ((dir == 0 && x <= 1) || (dir == 1 && y <= 1) || (dir == 2 && x >= arr_size - 2) || (dir == 3 && y >= arr_size - 2))
            continue;
        switch (dir){
            case 0:
                if (maze[x - 2][y] == border){
                    maze[x - 2][y] = skip;
                    maze[x - 1][y] = skip;
                }
                x -= 2;
                break;
            case 1:
                if (maze[x][y - 2] == border){
                    maze[x][y - 2] = skip;
                    maze[x][y - 1] = skip;
                }
                y -= 2;
                break;
            case 2:
                if (maze[x + 2][y] == border){
                    maze[x + 2][y] = skip;
                    maze[x + 1][y] = skip;
                }
                x += 2;
                break;
            case 3:
                if (maze[x][y + 2] == border){
                    maze[x][y + 2] = skip;
                    maze[x][y + 1] = skip;
                }
                y += 2;
                break;
            }

        flag = 1;
        for (int i = 0; i < arr_size; i++)
            for (int j = 0; j < arr_size; j++)
                if (i % 2 == 1 && j % 2 == 1 && maze[i][j] == border)
                    flag = 0;
    }

    for (int i = 0; i < arr_size; ++i) {
        printf("%s\n", maze[i]);
    }
    for(int i = 0; i < arr_size; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}