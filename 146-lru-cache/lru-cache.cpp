class Node{
    public :
        int k;
        int v;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->k = key;
            this->v = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

class LRUCache {
public:
    int size;
    unordered_map<int,Node*> hm;
    Node* dummy = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        this->size = capacity;
        dummy->next = tail;
        tail->prev = dummy;
    }
    
    int get(int key) {
        if(hm.find(key) == hm.end())
            return -1;
        Node* curr = hm.at(key);
        deleteNode(curr);
        addAtLast(curr);
        return curr->v;
    }
    
    void put(int key, int value) {
        if(hm.find(key) != hm.end()){
            Node* curr = hm.at(key);
            curr->v = value;
            deleteNode(curr);
            addAtLast(curr);
            return;
        }
        if(hm.size() == size){ 
            deleteNode(dummy->next);
        }
        Node* curr = new Node(key,value);
        addAtLast(curr);
    }

    void addAtLast(Node* curr){
        tail->prev->next = curr;
        curr->prev = tail->prev;
        curr->next = tail;
        tail->prev = curr;
        hm.insert({curr->k,curr});
    }
    void deleteNode(Node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        hm.erase(curr->k);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */