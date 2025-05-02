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
        if(head == NULL)
            return NULL;
        Node* p1 = head;
        while(p1 != NULL) {
            Node* n = new Node(p1->val);
            n->next = p1->next;
            p1->next = n;
            p1 = n->next;
        }
        p1 = head;
        while(p1 != NULL) {
            if(p1->random != NULL)
                p1->next->random = p1->random->next;
            p1 = p1->next->next;
        }
        p1 = head;
        Node* cloneHead = head->next;
        Node* p2 = cloneHead;
        while(p2->next != NULL) {
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = nullptr;
        p2->next = nullptr;
        return cloneHead;
    }
};