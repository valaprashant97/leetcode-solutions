int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int top = 0, front = 0, side = 0;

    for (int i = 0; i < gridSize; i++) {
        int maxRow = 0;
        int maxCol = 0;

        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                top++;
            }

            if (grid[i][j] > maxRow) {
                maxRow = grid[i][j];
            }

            if (grid[j][i] > maxCol) {
                maxCol = grid[j][i];
            }
        }

        front += maxRow;
        side += maxCol;
    }

    return top + front + side;
}