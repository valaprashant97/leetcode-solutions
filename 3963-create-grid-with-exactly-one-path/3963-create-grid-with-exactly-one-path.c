/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char** grid = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        grid[i] = malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++) {
            grid[i][j] = '#';
        }

        grid[i][n] = '\0';
    }

    // Open the first row
    for (int j = 0; j < n; j++) {
        grid[0][j] = '.';
    }

    // Open the last column
    for (int i = 0; i < m; i++) {
        grid[i][n - 1] = '.';
    }

    *returnSize = m;
    return grid;
}