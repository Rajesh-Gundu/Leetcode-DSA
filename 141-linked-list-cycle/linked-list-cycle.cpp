/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // using floyd's cycle detection algo
        if(head == NULL || head->next == NULL)
            return false;
        ListNode * sp = head;
        ListNode * fp = head;
        while(fp != NULL && fp->next != NULL){
            sp = sp->next;
            fp = fp->next->next;
            if(fp == sp)
                return true;
        }
        return false;
    }
};