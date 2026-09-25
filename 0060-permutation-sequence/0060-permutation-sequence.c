char* getPermutation(int n, int k) {
    static char result[10];
    int fact[10];
    int used[10] = {0};

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    k--;

    int pos = 0;

    for (int i = n; i >= 1; i--) {
        int block = fact[i - 1];
        int index = k / block;
        k %= block;

        int count = 0;

        for (int num = 1; num <= n; num++) {
            if (!used[num]) {
                if (count == index) {
                    result[pos++] = '0' + num;
                    used[num] = 1;
                    break;
                }
                count++;
            }
        }
    }

    result[pos] = '\0';

    return result;
}