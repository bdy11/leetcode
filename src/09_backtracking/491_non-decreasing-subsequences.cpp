class Solution {
private:
    vector<vector<int>>result;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex){
        if(path.size() > 1){
            result.push_back(path);
            // 不加return，因为要取树上的节点
        }
        unordered_set<int> uset; // 使用set对本层元素进行去重
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()){
                    continue;
                }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};