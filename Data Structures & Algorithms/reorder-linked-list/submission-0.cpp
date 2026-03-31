class Solution {
private:
    ListNode* reverse(ListNode *head) {
        ListNode *prev=NULL, *curr=head, *nxt;
        while(curr) {
            nxt = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        fast = reverse(fast);
        slow=head;
        ListNode *flag=slow;
        slow=slow->next;
        while(slow && fast) {
            flag->next=fast;
            fast=fast->next;
            flag=flag->next;
            flag->next=slow;
            slow=slow->next;
            flag=flag->next;
        }
    }
};
