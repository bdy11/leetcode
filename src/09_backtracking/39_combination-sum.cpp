/*
递归三部曲
1.确定函数参数及返回值
2. 确定递归终止条件
3. 确定单层递归逻辑
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void back_tracking(vector<int> &candidates, int target, int sum, int index)
    {
        if(sum > target) return;
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size() && sum + candidates[i] <= target;i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            back_tracking(candidates, target, sum, i);
            sum-= candidates[i];
            path.pop_back();
        } 
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0, 0);
        return result;
    }
};
