class Solution {
  List<int> twoSum(List<int> numbers, int target) {
    int start = 0;
    int end = numbers.length -1;
    while(start < end){
        int sum = numbers[start]+numbers[end];
        if (sum == target){
            return [start+1, end+1];
        }
        if(sum <target){
            start ++;
        }else{
            end--;
        }

    }return [];
  }
}