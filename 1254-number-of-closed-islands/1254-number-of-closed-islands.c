void dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i])
        return;

    if (grid[i][j] == 1)
        return;

    grid[i][j] = 1;

    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int cols = gridColSize[0];

    // Remove islands connected to the boundary
    for (int i = 0; i < gridSize; i++) {
        dfs(grid, gridSize, gridColSize, i, 0);
        dfs(grid, gridSize, gridColSize, i, cols - 1);
    }

    for (int j = 0; j < cols; j++) {
        dfs(grid, gridSize, gridColSize, 0, j);
        dfs(grid, gridSize, gridColSize, gridSize - 1, j);
    }

    // Count the remaining islands
    for (int i = 1; i < gridSize - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (grid[i][j] == 0) {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return count;
}