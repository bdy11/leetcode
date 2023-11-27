class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void back_tracking(vector<int> nums, int startIndex, vector<bool> &used){
        result.push_back(path);
        if(path.size() >= nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && used[i - 1] == false && nums[i] == nums[i-1]){
                continue;
            } 
            used[i] = true;
            path.push_back(nums[i]);
            back_tracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        back_tracking(nums, 0, used);
        return result;
    }
};