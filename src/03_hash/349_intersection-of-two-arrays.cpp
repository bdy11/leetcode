/*
这道题是典型的应用set的题。
先把数组1推入set1, 然后判断数组2的元素在不在set1里，如果不在，就把该元素推入set2。
使用unordered_set, 因为这种数据结构具有去重的特性。
最后把set2装到vector里，作为返回值。
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