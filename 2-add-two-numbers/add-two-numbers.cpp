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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int digit1 = (l1) ? l1->val : 0;
            int digit2 = (l2) ? l2->val : 0;
            int num = digit1 + digit2 + carry;
            ListNode* N = new ListNode(num%10);
            if(head == NULL)
                head = N;
            else
                cur->next = N;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
            carry = num/10;
            cur = N;
        }
        return head;
    }
};