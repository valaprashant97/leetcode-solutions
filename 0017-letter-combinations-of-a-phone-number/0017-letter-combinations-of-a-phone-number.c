
void solve(char *digits, int index, char *current,
           char **result, int *returnSize,
           char **mapping) {

    if (digits[index] == '\0') {
        current[index] = '\0';
        result[*returnSize] = malloc(index + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = mapping[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];

        solve(digits, index + 1, current,
              result, returnSize, mapping);
    }
}

char** letterCombinations(char* digits, int* returnSize) {

    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

    char *mapping[] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    int len = strlen(digits);

    int total = 1;

    for (int i = 0; i < len; i++) {
        total *= strlen(mapping[digits[i] - '0']);
    }

    char **result = malloc(total * sizeof(char *));
    char *current = malloc((len + 1) * sizeof(char));

    solve(digits, 0, current, result, returnSize, mapping);

    free(current);

    return result;
}
