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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        stack<int> st;
        ListNode* sp = head;
        ListNode* fp = head;
        while(fp != NULL && fp->next != NULL){
            st.push(sp->val);
            sp = sp->next;
            fp = fp->next->next;
        }
        if(fp != NULL)
            sp = sp->next;
        while(sp != NULL){
            if(sp->val != st.top())
                return false;
            sp = sp->next;
            st.pop();
        }
        return true;
    }
};