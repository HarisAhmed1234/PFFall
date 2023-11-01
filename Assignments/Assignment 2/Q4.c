#include <stdio.h>

int main() {
    int i = 0;
    int j = 0;
    char maze[5][5] = {
        {'S', 'O', 'O', 'W', 'W'},
        {'O', 'W', 'O', 'O', 'W'},
        {'O', 'O', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'E', 'W'}
    };

    printf("Maze path: ");

    while (maze[i][j] != 'E') {
        printf("(%d, %d) ", i, j);

        if (i + 1 < 5 && maze[i + 1][j] != 'W') {
            i++;
        } else if (j + 1 < 5 && maze[i][j + 1] != 'W') {
            j++;
        } else {
            printf("No path to the exit.");
            break;
        }
    }

    printf("(%d, %d) (Exit)\n", i, j);

    return 0;
}
