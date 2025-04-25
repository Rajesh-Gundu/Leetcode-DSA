class Node {
    public :
        int data;
        Node* next;
        Node(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

class MyLinkedList {
public:
    Node* head;
    int len;
    MyLinkedList() {
        this->head = nullptr;
        this->len = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        Node* tmp = head;
        for(int i=0;i<index;i++)
            tmp = tmp->next;
        return tmp->data;
    }
    
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        len++;
    }
    
    void addAtTail(int val) {
        len++;
        Node* n = new Node(val);
        if(head == nullptr) {
            head = n;
            return;
        }
        Node* t = head;
        while(t->next) {
            t = t->next;
        }
        t->next = n;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > len)
            return;
        else if(index == 0) {
            addAtHead(val);
            return;
        }
        else if(index == len) {
            addAtTail(val);
            return;
        }
        Node* n = new Node(val);
        Node* t = head;
        for(int i=0;i<index-1;i++) {
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len)
            return;
        len--;
        if(index == 0) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }
        Node* t = head;
        for(int i=0;i<index-1;i++) {
            t = t->next;
        }
        Node* d = t->next;
        t->next = t->next->next;
        delete d;
    }
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