char* reverseParentheses(char* s) {
    int n = strlen(s);
    char *stack = malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] != ')') {
            stack[++top] = s[i];
        } else {
            int j = top;

            while (stack[j] != '(')
                j--;

            int l = j + 1;
            int r = top;

            while (l < r) {
                char temp = stack[l];
                stack[l] = stack[r];
                stack[r] = temp;
                l++;
                r--;
            }

            while (j < top) {
                stack[j] = stack[j + 1];
                j++;
            }

            top--;
        }
    }

    stack[top + 1] = '\0';
    return stack;
}