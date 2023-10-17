/*
按照递推5部曲来做
1. 确定dp数组以及下标的含义
2. 确定递推公式
3. 确定dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};