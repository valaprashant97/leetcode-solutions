
char* toHex(int num) {
    if (num == 0)
        return "0";

    char *ans = malloc(9);
    char hex[] = "0123456789abcdef";

    int i = 0;
    unsigned int n = num;

    while (n > 0) {
        ans[i] = hex[n % 16];
        i++;
        n = n / 16;
    }

    ans[i] = '\0';

    // Reverse the answer
    for (int j = 0; j < i / 2; j++) {
        char temp = ans[j];
        ans[j] = ans[i - 1 - j];
        ans[i - 1 - j] = temp;
    }

    return ans;
}
