/*
这道题的初始化需要注意，由于每个小孩子至少分到一颗糖果，将candies数组1更合理。
第一遍循环，从左向右，如果右边的小孩rating比左边的高，那么就要分配比左边多1的糖果，否则该小孩只能得到默认的一个糖果。
第二遍循环，从右向左，同样，如果左边的小孩rating比右边的高，那么就要分配比右边多1的糖果，并且不能比第一次计算得到的糖果数少。
最后统计每个小孩得到的糖果数的总和即可。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                candys[i] = candys[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candys[i] = max(candys[i + 1] + 1, candys[i]);
            }
        }
        int ret = 0;
        for(int i = 0; i < candys.size(); i++){
            ret += candys[i];
        }
        return ret;
    }
};