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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        k = k%cnt;
        if(k == 0) return head;
        int i = 1;
        temp = head;
        while(i < (cnt-k)){
            i++;
            temp = temp->next;
        }
        ListNode* cur = temp->next;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next  = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};