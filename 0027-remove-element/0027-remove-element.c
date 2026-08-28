int removeElement(int* nums, int numsSize, int val) {
    int prt = 0;
    for(int i =0; i<numsSize;i++){
        if(nums[i]!=val){
            nums[prt] = nums[i];
            prt++;
        }
    }
    return prt;
}