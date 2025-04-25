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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* sp = head;
        ListNode* fp = head;
        while(fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp)
                break;
        }
        if(sp != fp)
            return nullptr;
        sp = head;
        while(sp != fp) {
            sp = sp->next;
            fp = fp->next;
        }
        return sp;
    }
};