class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=l1, *b=l2;
        ListNode *head = new ListNode(100);
        ListNode *temp = head;
        int carry=0;
        while(a && b) {
            int sum = a->val+b->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode *nwNode = new ListNode(sum);
            temp->next=nwNode;
            temp=temp->next;
            a=a->next;
            b=b->next;
        }
        while(a) {
            int sum = a->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode *nwNode = new ListNode(sum);
            temp->next=nwNode;
            temp=temp->next;
            a=a->next;
        }
        while(b) {
            int sum = b->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode *nwNode = new ListNode(sum);
            temp->next=nwNode;
            temp=temp->next;
            b=b->next;
        }
        if(carry!=0) {
            ListNode *nwNode = new ListNode(carry);
            temp->next=nwNode;
        }
        return head->next;
    }
};
