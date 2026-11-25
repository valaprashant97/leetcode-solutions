struct Pair {
    int val;
    int index;
};

int compare(const void* a, const void* b) {
    struct Pair* x = (struct Pair*)a;
    struct Pair* y = (struct Pair*)b;

    if (x->val < y->val) return -1;
    if (x->val > y->val) return 1;
    return x->index - y->index;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k <= 0) return false;

    struct Pair* arr = malloc(numsSize * sizeof(struct Pair));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(struct Pair), compare);

    for (int i = 1; i < numsSize; i++) {
        if (arr[i].val == arr[i - 1].val &&
            arr[i].index - arr[i - 1].index <= k) {
            free(arr);
            return true;
        }
    }

    free(arr);
    return false;
}
