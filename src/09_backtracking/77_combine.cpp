/*
用英语写注释太累了，还是先切换成中文。
本题回溯中带着递归。
递归三部曲:
1. 确定递归终止条件。本题中，当path中元素数为k时，说明找到一条path，本次递归终止
2. 确定函数参数, n 是循环的边界, k是path中元素的个数, startIndex是本次循环开始的位置
3. 确定递归逻辑
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void back_tracking(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
        }
        for(int i = startIndex; i <= n; i++){
            path.push_back(i);
            back_tracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        back_tracking(n, k, 1);
        return result;
    }
};