class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void back_tracking(vector<int> candidates, int target, int sum, int index, vector<bool> &used){
        if(sum > target) return;
        if(sum == target){
            result.push_back(path);
        }
        for(int i = index; i < candidates.size() && sum + candidates[i] <= target; i++){

            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            path.push_back(candidates[i]);
            sum += candidates[i];

            for(int j = 0; j < path.size(); j++){
                cout<< path[j] << " ";
            }
            cout<<endl;
            used[i] = true;
            back_tracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);

        back_tracking(candidates, target, 0, 0, used);
        return result;
    }
};