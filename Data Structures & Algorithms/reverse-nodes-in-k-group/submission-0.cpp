class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *curr=head, *prev=NULL, *nxt;
        while(curr) {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode *getKthNode(ListNode *temp, int k) {
        k--;
        while(temp && k>0) {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prevNode = NULL;
        while(temp) {
            ListNode *kthNode = getKthNode(temp, k);
            if(!kthNode) {
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(temp==head) {
                head=kthNode;
            }
            else {
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
