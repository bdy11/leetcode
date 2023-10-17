class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void back_tracking(int k, int n, int sum, int startIndex) {
        if(path.size() == k){
            if(sum == n) result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= 9; i++){
            sum += i;
            path.push_back(i);
            back_tracking(k, n, sum, i + 1);

            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        back_tracking(k, n, 0, 1);
        return result;
    }
};
