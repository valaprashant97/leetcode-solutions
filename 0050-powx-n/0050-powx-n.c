double myPow(double x, int n) {
    double result = 1.0;
    long long p = n;

    if (p < 0) {
        x = 1.0 / x;
        p = -p;
    }

    while (p > 0) {
        if (p % 2 == 1)
            result *= x;

        x *= x;
        p /= 2;
    }

    return result;
}
