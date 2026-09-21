char* intToRoman(int num) {
    static char result[20];
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0, j = 0;

    while (num > 0) {
        while (num >= values[i]) {
            num -= values[i];
            result[j++] = symbols[i][0];

            if (symbols[i][1] != '\0')
                result[j++] = symbols[i][1];
        }
        i++;
    }

    result[j] = '\0';
    return result;
}