class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr) {}
    };

    MyLinkedList() {
        dummyHead = new ListNode(0);
        _size = 0;
    }
    
    void printList(){
        int loop = _size;
        ListNode* cur = dummyHead;
        while(loop--){
            cout<<cur->next->val<< " ";
            cur = cur->next;
        }
        cout<<endl;
    }
    int get(int index) {
        if(index >= _size || index < 0) return -1;
        ListNode* cur = dummyHead;
        while(index--){
            cur = cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        _size++;
        //printList();
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        ListNode* newNode = new ListNode(val);
        cur->next = newNode;
        _size++;
        //printList();
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size || index < 0) return;
        ListNode* cur = dummyHead;
        while(index--){
            cur = cur->next;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
        //printList();
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) return;
        ListNode* cur = dummyHead;
        while(index--){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        _size--;
        
    }
private:
    ListNode* dummyHead;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */