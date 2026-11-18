
/**
 * Note: The returned array must be malloced.
 * The caller should free it.
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** ans = malloc(numsSize * sizeof(char*));
    *returnSize = 0;

    int i = 0;

    while (i < numsSize) {
        int start = nums[i];

        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        int end = nums[i];

        ans[*returnSize] = malloc(30 * sizeof(char));

        if (start == end) {
            sprintf(ans[*returnSize], "%d", start);
        } else {
            sprintf(ans[*returnSize], "%d->%d", start, end);
        }

        (*returnSize)++;
        i++;
    }

    return ans;
}
