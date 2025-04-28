/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return head;
        
        Node* cur = head;
        while(cur != NULL) {
            if(cur->child) {
                Node* nxt = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;

                Node* last = cur->next;
                while(last->next)
                    last = last->next;
                
                last->next = nxt;
                if(nxt)
                    nxt->prev = last;
            }
            cur = cur->next;
        }
        return head;
    }
};