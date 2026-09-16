char* convertToBase7(int num) {
    char *result = malloc(20);
    int i = 0, negative = 0;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    if (num < 0) {
        negative = 1;
        num = -num;
    }

    while (num > 0) {
        result[i++] = (num % 7) + '0';
        num /= 7;
    }

    if (negative)
        result[i++] = '-';

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}