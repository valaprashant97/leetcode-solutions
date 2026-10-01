char* convert(char* s, int numRows) {
    if (numRows == 1)
        return s;

    int len = strlen(s);

    char **rows = malloc(numRows * sizeof(char*));
    int *count = calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = malloc((len + 1) * sizeof(char));

    int row = 0;
    int dir = 1;

    for (int i = 0; i < len; i++) {
        rows[row][count[row]++] = s[i];

        if (row == numRows - 1)
            dir = -1;

        if (row == 0)
            dir = 1;

        row += dir;
    }

    char *ans = malloc(len + 1);
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < count[i]; j++)
            ans[k++] = rows[i][j];
    }

    ans[k] = '\0';

    for (int i = 0; i < numRows; i++)
        free(rows[i]);

    free(rows);
    free(count);

    return ans;
}