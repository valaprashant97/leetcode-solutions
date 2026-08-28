/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int)); 
    int startPrt = 0;
    int endPrt = numsSize-1;
    int prt =numsSize-1;

    while(startPrt<=endPrt){
        int ss =nums[startPrt]*nums[startPrt];
        int es =nums[endPrt]*nums[endPrt];
        if(ss>es){
            ans[prt] = ss;
            startPrt++;
        }else{
            ans[prt] = es;
            endPrt--;
        }
        prt--;
    }
    *returnSize = numsSize;
    return ans;
}
