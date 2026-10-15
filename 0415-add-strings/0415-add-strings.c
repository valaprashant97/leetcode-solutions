char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;

    char *result = malloc(10001 * sizeof(char));
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0)
            sum += num1[i--] - '0';

        if (j >= 0)
            sum += num2[j--] - '0';

        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[k] = '\0';

    // Reverse the result
    for (int a = 0, b = k - 1; a < b; a++, b--) {
        char temp = result[a];
        result[a] = result[b];
        result[b] = temp;
    }

    return result;
}