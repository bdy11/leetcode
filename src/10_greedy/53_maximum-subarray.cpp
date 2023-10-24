/*
从头开始计算连续和。发现新的最大连续和就更新。累加的过程中，如果发现连续和小于0，那么就从0开始计算连续和。
最后结果就是记录的最大连续和。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > result) result = count;
            if(count < 0) count = 0; 
        }
        return result;
    }
};