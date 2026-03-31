class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
        for(int i=0; i<lists.size(); i++) pq.push({lists[i]->val, lists[i]});
        ListNode *dummy = new ListNode(100);
        ListNode *temp = dummy;
        while(!pq.empty()) {
            temp->next=pq.top().second;
            temp=temp->next;
            ListNode *newNode = pq.top().second->next;
            pq.pop();
            if(newNode) pq.push({newNode->val, newNode});
        }
        return dummy->next;
    }
};
