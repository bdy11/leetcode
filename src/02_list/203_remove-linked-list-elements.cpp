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
使用虚拟头结点，可以使对链表的操作，具有一致性
首先创建一个虚拟头结点，从虚拟头结点开始遍历，判断下一个节点的值是否和目标值相等，如果相等，那么将下个节点指向下下个节点，
否则，将当前节点指向下一个节点
最后返回虚拟头结点的下一个节点。
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }

        return dummyHead->next;
        
    }
};