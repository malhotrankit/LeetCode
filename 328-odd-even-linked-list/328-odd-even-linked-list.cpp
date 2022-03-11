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
    inline ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *ptr1, *ptr2, *head2;
        if(head==NULL)
            return NULL;
        ptr1=head;
        ptr2=head;
        ptr2= ptr2->next;
        head2=ptr2;
        while(ptr1!=NULL&&ptr2!=NULL)
        {
            if(ptr1->next!=NULL)
            {
                ptr1->next = ptr1->next->next;
                ptr1 = ptr1->next;
            }
            if(ptr2->next!=NULL)
            {
                ptr2->next=ptr2->next->next;
                ptr2=ptr2->next;
            }
        }
        ptr1=head;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=head2;
        return head;
    }
};