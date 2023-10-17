/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。


示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false

提示:
1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
*/

/*solution
创建一个array 长度为26，用来记录26个字母的出现次数。
int count[26]

进行三次循环，
第一个循环遍历第一个string， 每个字母出现一次，就将对应字母的计数器加一
第二个循环遍历第二个string，每个字母出现一次，这次将对应字母的计数器减一

遍历一遍计数器，检查每个字母对应的计数器是否是0， 如果不是0，那么该字母在两个string里出现的次数不同，
不是有效的字母异位词

如果每个字母对应的计数器全部都是0，那么，两个字符串是字母异位词。

*/

#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++){
            count[t[j] - 'a']--;
        }
        for(int k = 0; k < 26; k++){
            if(count[k] != 0) return false;
        }

        return true;
    }
};