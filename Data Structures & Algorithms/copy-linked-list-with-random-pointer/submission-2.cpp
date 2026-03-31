class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *temp = head;
        while(temp) {
            Node *nw = new Node(temp->val);
            nw->next=temp->next;
            temp->next=nw;
            temp=temp->next->next;
        }
        temp=head;
        while(temp) {
            if (temp->random) temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp=temp->next->next;
        }
        Node *org = head;
        Node *nwHead = head->next;
        temp = head->next;
        while(org) {
            org -> next = org->next->next;
            if(temp->next) temp->next= temp->next->next;
            org=org->next;
            temp=temp->next;
        }
        return nwHead;
    }
};
