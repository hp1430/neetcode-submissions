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
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(100);
        ListNode *temp=dummy;
        ListNode *temp1=l1, *temp2=l2;
        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {
                temp->next = temp1;
                temp1=temp1->next;
            }
            else {
                temp->next = temp2;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        while(temp1) {
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        while(temp2) {
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode *head = lists[0];
        for(int i=1; i<lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }
};
