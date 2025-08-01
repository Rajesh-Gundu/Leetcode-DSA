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
            ListNode* cur = t.second;
            pq.pop();
            if(head == nullptr) {
                head = cur;
            }
            else {
                prev->next = cur;
            }
            prev = cur;
            if(cur->next) {
                pq.push({cur->next->val,cur->next});
            }
        }
        return head;
    }
};