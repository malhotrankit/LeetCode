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
    bool hasCycle(ListNode *head) 
    {
        ListNode *check1;
        int min = -100001, flag = 0;
        check1 = head;
        while(flag!=1&&check1!=NULL)
        {
            check1->val = min;
            if((check1->next)!=NULL && (check1->next->val)==min)
                flag=1;
            check1 = check1->next;
        }
        
        if(flag==1)
            return true;
        else
            return false;
    }
};