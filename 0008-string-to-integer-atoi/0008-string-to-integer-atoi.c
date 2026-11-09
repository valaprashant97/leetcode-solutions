int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long long num = 0;

    // Step 1: Skip spaces
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (s[i] == '+') {
        sign = 1;
        i++;
    }

    // Step 3: Convert digits to number
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');

        // Step 4: Check overflow
        if (sign * num > INT_MAX) {
            return INT_MAX;
        }

        if (sign * num < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(sign * num);
}