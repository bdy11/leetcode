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
 本题使用虚拟头结点，虚拟头结点的next指向head.
 开始时，让fast 和 slow都指向虚拟头。
让fast先移动n步。然后让fast和slow指针同时移动。fast最后要指向最后一个节点，而不能指向最后的额空节点，所以
while循环的条件是fast->next不能为空。
此时，slow指向的下一个节点即为需要删除的节点。此时删除该节点即可
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        while(n--){
            fast = fast->next;
        } 
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummyhead->next;
    }
};