/*
leet code link:
https://leetcode.com/problems/remove-element/


notes:

use fast / slow pointer.
fast pointer moves on every element and check if it equals val, if yes, fast pointer moves
to the next element and do nothing else. if not, copy the value that fast pointer points to, 
to the place where slow pointer points to .

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        for(fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};