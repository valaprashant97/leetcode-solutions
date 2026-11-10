
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target,
              int* returnSize, int** returnColumnSizes) {

    int **ans = malloc(sizeof(int*) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum = (long long)nums[i] + nums[j]
                              + nums[left] + nums[right];

                if (sum == target) {

                    int *temp = malloc(4 * sizeof(int));

                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[left];
                    temp[3] = nums[right];

                    ans[*returnSize] = temp;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;

                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return ans;
}
