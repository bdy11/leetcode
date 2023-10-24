/*
特殊情况输入只有一个数，那么返回1。
这道题关键是去重。
去重后讨论特殊情况只有一个数，返回1。
将数值进行去重后，形成的数组在各个区间内要么单调增，要么单调减。
两个端点，连同端点之间每个局部高点和局部低点的总和就是结果。
去重的逻辑在之前的题目中有用到过。

*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& n) {

        if(n.size() == 1) return 1;
 
        // remove duplicated number
        vector<int> nums;
        nums.push_back(n[0]);
        for(int i = 1; i < n.size(); i++){
            if(n[i] != n[i - 1]){          // 注意去重的逻辑
                nums.push_back(n[i]);
            } 
        }

        if(nums.size() == 1) return 1;

        int ans = 1;
        for(int i = 1; i < nums.size() - 1; i++){
            if((nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            ||(nums[i] < nums[i - 1] && nums[i] < nums[i + 1])){
                ans++;
            }
        }
        ans++;

        return ans;
    }
};