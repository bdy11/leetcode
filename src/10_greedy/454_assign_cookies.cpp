/*
优先用大饼干满足需求比较大的胃口。
这需要对胃口和饼干大小做排序。
对胃口进行一遍从大到小的遍历，然后分配饼干。这个分配过程体现在，将最大的饼干，一旦满足某个胃口，就分配出去。
重复这个过程，直到饼干分配完。

g 数组是小孩子的胃口，s数组是饼干的大小。
首先要对两个数组进行排序，按照从小到大的顺序。
按照小孩子的胃口进行从大到小的遍历，判断最大的饼干能满足哪个小孩子的胃口。
如果某个饼干能满足某个小孩子的胃口，那么看次大的饼干能满足哪个小孩子的胃口。
每次满足条件，就将结果加一。最后返回结果。
*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        int index = s.size() - 1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = g.size() - 1; i >= 0; i--){
            if(index >= 0 && s[index] >= g[i]){
                index--;
                result++;
            }
        }
        return result;
    }
};