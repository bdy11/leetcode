/*
逆波兰表达式求值
这道题也是典型应用栈解决的题目。
遇到非操作符的字符串，就转换成数字，推入栈中，遇到字符，则取栈顶两个元素，进行操作。操作结果继续存入栈中。
最后栈顶的元素就是所求结果。
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a = 0;
        int b = 0;
        for(auto t : tokens){
            if(t != "+" && t != "-" && t != "*" && t != "/"){
                st.push(stoi(t));
            }else {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                if(t == "+") st.push(a + b);
                if(t == "-") st.push(a - b);
                if(t == "*") st.push(a * b);
                if(t == "/") st.push(a / b);
            }
        }
        return st.top();
    }
};