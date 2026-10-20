int sortableIntegers(int* nums, int numsSize) {
    int n = numsSize;
    int prefMax[n + 1];
    int suffMin[n + 1];
    int prefDrop[n];

    prefMax[0] = 0;

    for (int i = 0; i < n; i++) {
        prefMax[i + 1] = prefMax[i] > nums[i]
                         ? prefMax[i] : nums[i];
    }

    suffMin[n] = 100001;

    for (int i = n - 1; i >= 0; i--) {
        suffMin[i] = suffMin[i + 1] < nums[i]
                     ? suffMin[i + 1] : nums[i];
    }

    prefDrop[0] = 0;

    for (int i = 1; i < n; i++) {
        prefDrop[i] = prefDrop[i - 1];

        if (nums[i - 1] > nums[i]) {
            prefDrop[i]++;
        }
    }

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        if (n % k != 0) {
            continue;
        }

        int valid = 1;

        for (int start = 0; start < n; start += k) {
            int end = start + k - 1;

            int drops = prefDrop[end] - prefDrop[start];

            if (nums[end] > nums[start]) {
                drops++;
            }

            if (drops > 1 || prefMax[start] > suffMin[start]) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            ans = ans + k;
        }
    }

    return ans;
}