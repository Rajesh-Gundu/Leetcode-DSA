class Node{
    public :
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;
        Node(int key,int val) {
            this->key = key;
            this->val = val;
            freq = 1;
            prev = next = nullptr;
        }
};

class LFUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;
    unordered_map<int,Node*> freqMp;
    Node* dummy;
    Node* tail;

    LFUCache(int capacity) {
        cap = capacity;
        dummy = new Node(-1,-1);
        tail = new Node(-1,-1);
        dummy->next = tail;
        tail->prev = dummy;
        dummy->freq = 0;
        tail->freq = 0;
        mp.clear();
        freqMp.clear();
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        Node* n = mp[key];
        deleteNode(n);
        increaseFreq(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            Node* n = mp[key];
            n->val = value;
            deleteNode(n);
            increaseFreq(n);
            return;
        }
        if(mp.size() == cap) {
            Node* n = dummy->next;
            mp.erase(n->key);
            int curFreq = n->freq;
            int prevFreq = n->prev->freq;
            if(n == freqMp[curFreq]) {
                if(curFreq == prevFreq) {
                    freqMp[curFreq] = n->prev;
                }
                else {
                    freqMp.erase(curFreq);
                }
            }
            deleteNode(dummy->next);
        }
        Node* n = new Node(key,value);
        mp[key] = n;
        if(freqMp.count(1)) {
            addAfterNode(freqMp[1],n);
        }
        else {
            addAfterNode(dummy,n);
        }
        freqMp[1] = n;
    }

    void deleteNode(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void addAfterNode(Node* p, Node* n) {
        n->next = p->next;
        n->prev = p;
        p->next = n;
        n->next->prev = n;
    }

    void increaseFreq(Node* n) {
        int curFreq = n->freq;
        int prevFreq = n->prev->freq;
        if(n == freqMp[curFreq]) {
            if(curFreq == prevFreq) {
                freqMp[curFreq] = n->prev;
            }
            else {
                freqMp.erase(curFreq);
            }
        }
        if(freqMp.count(curFreq+1)) {
            addAfterNode(freqMp[curFreq+1],n);
        }
        else if(freqMp.count(curFreq)) {
            addAfterNode(freqMp[curFreq],n);
        }
        else {
            addAfterNode(n->prev,n);
        }
        freqMp[curFreq+1] = n;
        n->freq += 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */