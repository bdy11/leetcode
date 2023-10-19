/*
solution:
遍历的终止条件是 i < s.size() / 2;
交换的元素是i 和 s.size() - i - 1
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++){
            swap(s[i], s[s.size() - i - 1]);
        }        
    }
};