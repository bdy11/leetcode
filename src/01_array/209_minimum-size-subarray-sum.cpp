/*
这道题类似于双指针解法，loop over right指针, 更新sum
每一次right指针变更位置后，left指针要跟进，找到满足条件的最小区间
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                int length = right - left + 1;
                result = min(result, length);
                sum -= nums[left];
                left++;
            }
        }
        if(result != INT_MAX) return result;
        else return 0;
    }
};