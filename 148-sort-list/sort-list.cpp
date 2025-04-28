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
    ListNode* merge(ListNode* h1,ListNode* h2) {
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(h1 && h2) {
            ListNode* tmp;
            if(h1->val <= h2->val) {
                tmp = h1;
                h1 = h1->next;
            }
            else {
                tmp = h2;
                h2 = h2->next;
            }
            if(head == NULL)
                head = tmp;
            else
                prev->next = tmp;
            prev = tmp;
        }
        if(h1)
            prev->next = h1;
        else
            prev->next = h2;
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
};