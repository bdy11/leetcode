class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void back_tracking(vector<int> nums, vector<bool> &used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                back_tracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        back_tracking(nums, used);
        return result;
    }
};