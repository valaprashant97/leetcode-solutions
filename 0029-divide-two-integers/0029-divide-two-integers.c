int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    long long a = dividend;
    long long b = divisor;

    int sign = 1;

    if (a < 0) {
        a = -a;
        sign = -sign;
    }

    if (b < 0) {
        b = -b;
        sign = -sign;
    }

    long long result = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    return sign == 1 ? result : -result;
}