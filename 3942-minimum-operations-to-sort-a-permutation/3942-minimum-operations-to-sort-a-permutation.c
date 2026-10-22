int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int zero = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero = i;
            break;
        }
    }

    int ans = 1000000000;

    for (int step = -1; step <= 1; step += 2) {
        int valid = 1;

        for (int i = 1; i < n; i++) {
            int prev = (zero + (i - 1) * step + n) % n;
            int curr = (zero + i * step + n) % n;

            if (nums[prev] > nums[curr]) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            if (step == 1) {
                if (zero < ans)
                    ans = zero;
                if (n - zero + 2 < ans)
                    ans = n - zero + 2;
            } else {
                if (zero + 2 < ans)
                    ans = zero + 2;
                if (n - zero < ans)
                    ans = n - zero;
            }
        }
    }

    return ans == 1000000000 ? -1 : ans;
}