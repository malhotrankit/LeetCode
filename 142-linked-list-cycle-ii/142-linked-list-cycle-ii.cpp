/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
        ListNode *detectCycle(ListNode *head) 
        {
            ListNode *slow, *fast;
            slow = fast = head;
            while(fast!=NULL&&slow!=NULL)
            {
                if(fast->next!=NULL)
                    fast = fast->next->next;
                else
                    fast=NULL;
                slow = slow->next;
                if(fast==slow)
                    break;
            }
            if(fast!=NULL&&slow!=NULL&&fast==slow)
            {
                fast=head;
                while(fast!=slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
            else
                return NULL;
        
        }
};