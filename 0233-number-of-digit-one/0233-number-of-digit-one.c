int countDigitOne(int n) {
    int count = 0;

    for (long i = 1; i <= n; i *= 10) {
        long div = i * 10;

        count += (n / div) * i;

        long long rem = n % div;

        if (rem >= i) {
            if (rem >= 2 * i - 1)
                count += i;
            else
                count += rem - i + 1;
        }
    }

    return count;
}