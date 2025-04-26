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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        ListNode* cur = NULL;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                cur = list1;
                list1 = list1->next;
            }
            else{
                cur = list2;
                list2 = list2->next;
            }
            if(head == nullptr) {
                head = cur;
            }
            else {
                prev->next = cur;
            }
            prev = cur;
        }
        if(list1 == NULL)
            cur = list2;
        else
            cur = list1;
        prev->next = cur;
        return head;
    }
};