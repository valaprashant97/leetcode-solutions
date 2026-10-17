int numPrimeArrangements(int n) {
    int prime = 0;
    long long a = 1, b = 1;
    int mod = 1000000007;

    for (int i = 2; i <= n; i++) {
        int count = 0;

        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                count++;
        }

        if (count == 2)
            prime++;
    }

    for (int i = 1; i <= prime; i++)
        a = (a * i) % mod;

    for (int i = 1; i <= n - prime; i++)
        b = (b * i) % mod;

    return (a * b) % mod;
}