/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* h1 = head;
        int n = 1;
        ListNode* p1 = h1;
        while(n < k && p1 != NULL) {
            p1 = p1->next;
            n++;
        }
        if(p1 == NULL)  return h1;
        ListNode* t = p1->next;
        p1->next = NULL;
        ListNode* ans = reverseLL(h1);
        h1->next = reverseKGroup(t,k);
        return ans; 
    }

    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = NULL;
        ListNode* rev = NULL;
        while(head != NULL) {
            cur = head;
            head = head->next;
            cur->next = rev;
            rev = cur;
        }
        return rev;
    }
};