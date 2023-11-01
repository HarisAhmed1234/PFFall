#include <stdio.h>

int main() {
    int n, m, max = -1;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);
    int arr[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int minsize = n > m ? m : n;
    int count = 0;
    int flag = 1;

    for (int x = minsize; x > 0; x--) {
        for (int y = 0; y < n - x + 1; y++) {
            for (int z = 0; z < m - x + 1; z++) {
                flag = 1;
                for (int i = 0; i < x && flag == 1; i++) {
                    for (int j = 0; j < x && flag == 1; j++) {
                        if (arr[i + y][j + z] == 0) {
                            flag = 0;
                        }
                    }
                }
                if (flag == 1) {
                    count = x;
                    printf("Coordinate: (%d,%d) -> (%d,%d)\nSize: %d\n", y, z, y + count - 1, z + count - 1, count);
                }
            }
        }
    }

    if (count == 0) {
        printf("No square of 1s found.");
    }

    return 0;
}
