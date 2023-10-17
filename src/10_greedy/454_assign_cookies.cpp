/*
优先用大饼干满足需求比较大的胃口。
这需要对胃口和饼干大小做排序。
对胃口进行一遍从大到小的遍历，然后分配饼干。这个分配过程体现在，将最大的饼干，一旦满足某个胃口，就分配出去。
重复这个过程，直到饼干分配完。
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