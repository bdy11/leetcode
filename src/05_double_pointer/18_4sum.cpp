/*
18. 4Sum
Medium
10.5K
1.2K
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

/*
solution
if we use brutal force, the complexity will be O(N,4)
we use double pointer to make the complexity O(N, 3)

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        while(it!= nums.end()){
            cout <<*it<<" ";
            it++;
        } 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target && nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] > 0 && nums[i] + nums[j] > target) break;
                if(j > i+1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    }else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    }else{
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }

            }
        }
        return result;
    }
};