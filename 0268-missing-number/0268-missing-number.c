int missingNumber(int* nums, int numsSize) {
    int range = numsSize;
    int actualSum = (range * (range + 1))/2; /// (n*(n+1))/2
    // actual sum when the missing numbers is presant in array.

    int currentSum = 0;

    for(int i =0;i<numsSize;i++){
        currentSum = currentSum + nums[i];
    }
    int ans = actualSum - currentSum;

    return ans;
}