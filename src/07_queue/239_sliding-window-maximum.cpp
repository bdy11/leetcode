/*
这道题解题关键是将滑动窗口做成一个单调递减数列来维护。
pop操作时，如果要pop的值等于队列front的值，才弹出，否则不弹出。
Push操作时，比较队列末尾的元素与要弹进队列的值得大小，如果队列末尾的值小于要弹入的值，就将队列末尾的值弹出，直到队列形成单调队列。
front操作则直接返回队列的front元素的值，一定是滑动窗口的最大值。

*/
class Solution {
private:
    class MyQueue{
    public:
        deque<int> que;
        void push(int val){
            while(!que.empty() && que.back() < val){
                que.pop_back();
            }
            que.push_back(val);
        }
        void pop(int val){
            if(!que.empty() && val == que.front()){
                que.pop_front();
            }
        }
        int front(){
            return que.front();
        }
    };
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = 0; i < nums.size() - k; i++){
            que.pop(nums[i]);
            que.push(nums[i + k]);
            result.push_back(que.front());
        }
        return result;
    }
};