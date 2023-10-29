/*
从全局角度看，(1)如果所有加油站油的总量小于所有路程所需油量，那么没有满足条件的路径。
接下来的思路很巧妙，
这里面有一个隐含逻辑，如果所有加油站油的总量大于等于所有路程所需油量，一定的存在一个index，从这个index循环一周，使得cur_sum一直不小于0。
从Index 0开始，排除所有不满足条件的Index。怎么排除呢，统计经过每个加油站剩余油量减去到达下一站所需油量的总和cur_sum，如果这个和小于0，那么就从下一个Index重新统计，并且记录下一个index的值。不断重复然后到最后结束。
计算找到的这个最后使cur_sum小于0的位置，那么意味着之后的所有位置加油站存油量减去所需油量的余额，足以将之前的cur_sum填平，除非不满足条件1。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int index = 0;
        for(int i = 0; i < gas.size(); i++){
            total_sum += gas[i] - cost[i];
            cur_sum += gas[i] - cost[i];
            if(cur_sum < 0){
                index = i + 1;
                cur_sum = 0;
            }
        } 
        if(total_sum < 0) return -1;
        return index;
    }
};