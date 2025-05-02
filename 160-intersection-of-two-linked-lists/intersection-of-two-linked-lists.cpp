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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        // ListNode* h1 = headA;
        // ListNode* h2 = headB;
        // while(h1 != h2){
        //     if(h1 == NULL)
        //         h1 = headB;
        //     else
        //         h1 = h1->next;
        //     if(h2 == NULL)
        //         h2 = headA;
        //     else
        //         h2 = h2->next;
        // }
        // return h1;

        ListNode * temp = headA;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        temp = headB;
        int m = 0;
        while(temp != NULL){
            m++;
            temp = temp->next;
        }

        ListNode * t1;
        if(n > m){
            temp = headA;
            t1 = headB;
        }
        else{
            temp = headB;
            t1 = headA;
        }
        int cnt = 0;
        while(temp != NULL){
            if(cnt < abs(n-m)){
                cnt++;
            }
            else{
                if(temp == t1)
                    return temp;
                t1 = t1->next;
            }
            temp = temp->next;
        }
        return NULL;
    }
};