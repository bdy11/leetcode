/*
这道题思路很简单，每个股票上涨的日子的涨幅，加起来即所求结果。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]){
                profit = profit + prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};