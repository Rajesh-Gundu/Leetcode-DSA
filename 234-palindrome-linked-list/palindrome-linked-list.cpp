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
    bool compareLL(ListNode* h1,ListNode* h2) {
        while(h1 && h2) {
            if(h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* prev = nullptr;
        while(head) {
            cur = head;
            head = head->next;
            cur->next = prev;
            prev = cur;
        }
        return prev;
    }

    int getLength(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr)
            return true;
        int n = getLength(head);
        int mid = (n+1)/2;
        ListNode* t = head;
        for(int i=1;i<mid;i++) {
            t = t->next;
        }
        ListNode* h2 = reverseLL(t->next);
        t->next = nullptr;
        return compareLL(head,h2);
    }
};