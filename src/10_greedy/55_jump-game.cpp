/*
这道题的集体思路很明确了，就是从头到尾更细每一次跳跃后能到的最远距离。
最开始的思路是，依次遍历数组的每一个元素，计算相应的最大可达距离。
而当最远距离大于等于最后一个元素的下标时，即返回TRUE。
而当最远距离不超过当前元素下表时，返回FALSE。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdist = 0;
        for(int i = 0; i < nums.size(); i++){
            maxdist = max(maxdist, i + nums[i]);
            if(maxdist >= nums.size() - 1) return true;
            if(maxdist <= i) return false;
        }
        return false;
    }
};
/*
以上解法其实是不容易理解的。更优的解法是用maxdist限制循环的结束
循环执行的次数是不固定的，只要i <= maxdist就继续执行。执行过程中如果达到最后一个元素位置，即返回TRUE
否则意味着不能到达。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdist = 0;
        for(int i = 0; i <= maxdist; i++){
            maxdist = max(maxdist, i + nums[i]);
            if(maxdist >= nums.size() - 1) return true;
        }
        return false;
    }
};