char* multiply(char* num1, char* num2) {
    if (num1[0] == '0' || num2[0] == '0')
        return "0";

    int n = strlen(num1);
    int m = strlen(num2);

    int *result = calloc(n + m, sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            int a = num1[i] - '0';
            int b = num2[j] - '0';

            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = a * b + result[pos2];

            result[pos2] = sum % 10;
            result[pos1] += sum / 10;
        }
    }

    char *ans = malloc(n + m + 1);

    int k = 0;
    int start = 0;

    while (start < n + m && result[start] == 0)
        start++;

    while (start < n + m)
        ans[k++] = result[start++] + '0';

    ans[k] = '\0';

    free(result);

    return ans;
}