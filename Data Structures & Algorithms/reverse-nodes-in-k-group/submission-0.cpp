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
ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){return head;}
        ListNode *prev=NULL,*cur=head,*forw=head->next;
        while(forw!=NULL)
        {
            cur->next = prev;
            prev=cur;
            cur=forw;
            forw=forw->next;
        }
        cur->next = prev;
        return cur;
    }

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr=head;
        if(!ptr){return head;}
        for(int i=1;i<k;i++)
        {
            ptr=ptr->next;
            if(!ptr){return head;}
        }
        ListNode* temp = ptr->next;
        ptr->next = NULL;
        ptr = head;
        head=reverseList(head);
        ptr->next = reverseKGroup( temp,  k);
       
        return head;
    }
};
