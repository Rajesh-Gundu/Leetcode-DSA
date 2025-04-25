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
        int cnt = 0;
        ListNode*  temp = head;
        while(temp != NULL && cnt <= 10000){
            cnt++;
            temp = temp->next;
        }
        if(temp == NULL)
            return false;
        return true;
    }
};