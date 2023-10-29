/*
这道题
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums;
        unordered_set<int> ret;
        for(int num : nums1){
            nums.insert(num);
        }
        for(int num : nums2)
        if(nums.find(num) != nums.end()){
            ret.insert(num);
        }
        vector<int> result(ret.begin(), ret.end());
        return result;
    }
};