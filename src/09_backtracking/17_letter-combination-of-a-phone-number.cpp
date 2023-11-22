/*
这道题从暴力解法出发，就是对每个数字对应的letters里的字符，一层又一层的循环，
所以呢，递归中，循环的也是每个数字对应的letters
字符到数字的映射通过一个letterMap来实现，格式为长度为10的string数组。
先将输入的数字从字符格式转为int的数字格式，然后这个数字作为letterMap的Index获取对应的Letters。
递归结束的条件是，string s长度为digits长度，此时将s存入结果result中并返回。
*/

class Solution {
private:
    const string letterMap[10] = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", //7
        "tuv", // 8
        "wxyz" // 9
    };
    vector<string> result;
    string s;
    void back_tracking(string digits, int index){
        if(s.size() == digits.size()){
            result.push_back(s);
            return;
        }
        string letters = letterMap[digits[index] - '0'];
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            back_tracking(digits, index + 1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        back_tracking(digits, 0);
        return result;
    }
};