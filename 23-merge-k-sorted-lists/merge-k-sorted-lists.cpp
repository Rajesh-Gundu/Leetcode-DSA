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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]) {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if(head == nullptr) {
                head = t.second;
            }
            else {
                prev->next = t.second;
            }
            prev = t.second;
            if(t.second->next) {
                pq.push({t.second->next->val,t.second->next});
            }
        }
        return head;
    }
};