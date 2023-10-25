
/*
这道题首先的想法就是，将数组从小到大排序，然后将第一个元素取反。之后再次排序，再将第一个数组取反。重复k次。
这样写代码很简单，提交也能通过，但代码运行速度很慢。
优化一下得到如下代码。
现将前面的负数反转，每次k--。如果这些操作后，K依然大于0，那么再次排序，然后把第一个元素反转k次。
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
            }else{
                break;
            }
        }
        sort(nums.begin(), nums.end());
        if(k % 2 == 1) nums[0] *= -1;
        int res = 0;
        for(int j = 0; j < nums.size(); j++){
            res += nums[j];
        }

        return res;
    }
};