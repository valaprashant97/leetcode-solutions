
void solve(int* nums, int numsSize, int* used,
           int* path, int** result,
           int* returnSize, int** returnColumnSizes,
           int depth) {

    if (depth == numsSize) {
        result[*returnSize] = malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }

        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            path[depth] = nums[i];

            solve(nums, numsSize, used, path,
                  result, returnSize, returnColumnSizes,
                  depth + 1);

            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    int total = 1;
    for (int i = 1; i <= numsSize; i++) {
        total *= i;
    }

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    int* used = calloc(numsSize, sizeof(int));
    int* path = malloc(numsSize * sizeof(int));

    solve(nums, numsSize, used, path,
          result, returnSize, returnColumnSizes, 0);

    free(used);
    free(path);

    return result;
}
