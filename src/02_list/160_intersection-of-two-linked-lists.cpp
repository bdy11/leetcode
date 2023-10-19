/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
首先计算两个list的长度差k，如果第一个List长度小于第二个List，那么交换两个头结点。
先从headA向后遍历k步，然后从headA和headB=同时遍历，直到headA == headB，并返回，这个节点就是第一个相遇的节点。
否则返回空指针。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != nullptr){
            temp1 = temp1->next;
            m++;
        }
        while(temp2 != nullptr){
            temp2 = temp2->next;
            n++;
        }
        temp1 = headA;
        temp2 = headB;
        if(n > m){
            swap(temp1, temp2);
        }
        int k = abs(m - n);
        while(k--){
            temp1 = temp1->next;
        }
        while(temp1 != nullptr){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};