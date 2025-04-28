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
        int n = 0;
        ListNode* cur = head;
        while(cur) {
            n++;
            cur = cur->next;
        }
        int cnt = (n+1)/2 - 1;
        cur = head;
        while(cnt--) {
            cur = cur->next;
        }
        ListNode* head1 = cur->next;
        cur->next = NULL;
        head = sortList(head);
        head1 = sortList(head1);
        return merge(head,head1);
    }
};