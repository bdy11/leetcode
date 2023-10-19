/*
这是一道基础的字符串题目
每2k个字符进行一次操作，调用reverse函数操作子字符串
对剩下的字符串再调用reverse进行反转
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i+=2*k){
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};