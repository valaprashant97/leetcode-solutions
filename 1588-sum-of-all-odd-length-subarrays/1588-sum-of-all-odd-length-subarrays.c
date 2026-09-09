int sumOddLengthSubarrays(int* arr, int arrSize) {
    int total = 0;

    for (int i = 0; i < arrSize; i++) {
        int sum = 0;

        for (int j = i; j < arrSize; j++) {
            sum += arr[j];

            int length = j - i + 1;

            if (length % 2 == 1) {
                total += sum;
            }
        }
    }
    return total;
}