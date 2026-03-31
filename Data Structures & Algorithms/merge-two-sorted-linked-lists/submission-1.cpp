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
        ListNode *temp, *flag;
        ListNode *a=list1, *b=list2;
        if(!a && !b) return NULL;
        if(!a) return b;
        if(!b) return a;
        if(a->val <= b->val) {
            temp = a;
            flag = a;
            a = a->next;
        }
        else {
            temp = b;
            flag = b;
            b = b->next;
        }
        while(a && b) {
            if(a->val <= b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(a==NULL) temp->next=b;
        else temp->next=a;
        return flag;
    }
};