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

        for(int i = index; i < candidates.size();i++){
            sum += candidates[i];
            path.push_back(candidates[i]);

            // print out path to show the back tracking steps
            for(int j = 0; j < path.size(); j++){
                cout<< path[j]<< " ";
            }
            cout<<endl;
            back_tracking(candidates, target, sum, i);
            sum-= candidates[i];
            path.pop_back();
        } 
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        back_tracking(candidates, target, 0, 0);
        return result;
    }
};
