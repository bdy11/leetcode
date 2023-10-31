/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

示例：

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。
*/

/*
解题思路
此题与检查括号一个问题。
将字符串的每一个字符推进栈。
将第一个字符推进栈，然后从第二个字符开始遍历
遍历字符串,当栈不为空，且当前字符等于栈顶字符，那么将栈顶字符推出栈，丢弃该字符和栈顶字符
这里需要注意，使用栈里元素前，先检查栈内是否为空。
否则将该字符推入栈

将栈里字符存进新定义的 string result里。
因为stack是先进后出，当前result是倒序的，需要将result字符串反转。

返回result.


*/
class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size() <= 1) return s;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};