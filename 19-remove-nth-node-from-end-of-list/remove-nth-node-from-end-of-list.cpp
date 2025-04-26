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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        if(n == len){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        int i = 1;
        temp = head;
        while(i < (len-n)){
            i++;
            temp = temp->next;
        }
        ListNode* node = temp->next;
        temp->next = temp->next->next;
        delete node;
        return head;
    }
};