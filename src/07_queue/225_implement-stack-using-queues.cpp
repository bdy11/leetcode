class MyStack {
private:
    queue<int> que1;
    queue<int> que2;
public:
    MyStack() {
        que1 = {};
        que2 = {};
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        for(int i = 0; i < size - 1; i++){
            que2.push(que1.front());
            que1.pop();
        }
        int ret = que1.front();
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return ret;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};