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
        unordered_set<ListNode*> myset;
        ListNode* cur = head;
        while(cur != NULL){
            if(myset.find(cur) != myset.end())
                return cur;
            myset.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};