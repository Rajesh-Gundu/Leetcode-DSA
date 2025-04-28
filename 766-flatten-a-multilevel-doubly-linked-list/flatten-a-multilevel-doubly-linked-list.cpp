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
                cur->next = flatten(cur->child);
                cur->next->prev = cur;
                cur->child = NULL;

                while(cur->next)
                    cur = cur->next;
                
                if(nxt)  {
                    cur->next = nxt;
                    nxt->prev = cur;
                }
            }
            cur = cur->next;
        }

        return head;
    }
};