#include <stdlib.h>

void generate(char** ans, char* str, int n, int open, int close, int* count, int pos) {
    if (pos == 2 * n) {
        str[pos] = '\0';

        ans[*count] = malloc((2 * n + 1) * sizeof(char));

        for (int i = 0; i <= 2 * n; i++)
            ans[*count][i] = str[i];

        (*count)++;
        return;
    }

    if (open < n) {
        str[pos] = '(';
        generate(ans, str, n, open + 1, close, count, pos + 1);
    }

    if (close < open) {
        str[pos] = ')';
        generate(ans, str, n, open, close + 1, count, pos + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int total = 10000;

    char** ans = malloc(total * sizeof(char*));
    char* str = malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    generate(ans, str, n, 0, 0, returnSize, 0);

    free(str);

    return ans;
}