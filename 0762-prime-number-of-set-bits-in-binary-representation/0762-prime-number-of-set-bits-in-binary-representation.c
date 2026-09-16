int countPrimeSetBits(int left, int right) {
    int count = 0;

    for (int num = left; num <= right; num++) {
        int n = num;
        int setBits = 0;

        while (n > 0) {
            setBits += n & 1;
            n >>= 1;
        }

        if (setBits > 1) {
            int isPrime = 1;

            for (int i = 2; i * i <= setBits; i++) {
                if (setBits % i == 0) {
                    isPrime = 0;
                    break;
                }
            }

            if (isPrime) {
                count++;
            }
        }
    }

    return count;
}