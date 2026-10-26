
long long dfs(int** grid, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        return 0;

    long long sum = grid[i][j];
    grid[i][j] = 0;

    sum += dfs(grid, m, n, i + 1, j);
    sum += dfs(grid, m, n, i - 1, j);
    sum += dfs(grid, m, n, i, j + 1);
    sum += dfs(grid, m, n, i, j - 1);

    return sum;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                long long sum = dfs(grid, m, n, i, j);

                if (sum % k == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}
