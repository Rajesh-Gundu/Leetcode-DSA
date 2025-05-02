/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* tmp = head;
        mp[nullptr] = nullptr;
        while(tmp) {
            Node* n = new Node(tmp->val);
            mp[tmp] = n;
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp) {
            Node* c = mp[tmp];
            c->next = mp[tmp->next];
            c->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};