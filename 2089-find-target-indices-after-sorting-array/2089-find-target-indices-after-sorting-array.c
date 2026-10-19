/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int i, less = 0, equal = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] < target)
            less++;
        else if (nums[i] == target)
            equal++;
    }

    *returnSize = equal;

    int *ans = (int*)malloc(equal * sizeof(int));

    for (i = 0; i < equal; i++) {
        ans[i] = less + i;
    }

    return ans;
}