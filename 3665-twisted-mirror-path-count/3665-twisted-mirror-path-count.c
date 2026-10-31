
int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int MOD = 1000000007;

    int* dp = (int*)calloc(n, sizeof(int));

    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        int left = 0;

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                int temp = left;
                left = dp[j];
                dp[j] = temp;
            } else {
                int total = (left + dp[j]) % MOD;
                left = total;
                dp[j] = total;
            }
        }
    }

    int ans = dp[n - 1];
    free(dp);

    return ans;
}
