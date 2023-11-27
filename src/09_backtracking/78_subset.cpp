class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void back_tracking(vector<int> nums, int startIndex){
        result.push_back(path);
        if(path.size() >= nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            back_tracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        back_tracking(nums, 0);
        return result;
    }
};