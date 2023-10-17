/*
solution 
use double pointer
1. create a vector of the same size as of input vector to store results
2. move the pointer from two ends until they meet
3. put squares into result vector from end to the beginning, to avoid additional resource sonsumption.
s
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;
        while(k >= 0 && left <= right){
            if(abs(nums[left]) < abs(nums[right])){
                result[k--] = pow(nums[right], 2);
                right--;
            }else{
                result[k--] = pow(nums[left], 2);
                left++;
            }
        }
        return result;
    }
};