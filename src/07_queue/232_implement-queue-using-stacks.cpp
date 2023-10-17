/*
用栈实现队列的方法
定义两个栈，一个为入栈，一个为出栈
push操作将元素推进入栈
Pop操作时，从出栈拿元素
如果出栈为空，那么就将入栈的所有元素放入出栈。
Peek操作和pop操作类似

*/
class MyQueue {
private:
    stack<int> stIn;
    stack<int> stOut;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    int peek() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */