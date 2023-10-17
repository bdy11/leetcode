/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 本题不需要使用虚拟头节点
 需要用temp节点保存下一个要处理的节点
 pre和cur节点分别记录前节点和当前节点
 需要注意的是，最后返回的是pre节点
 
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};