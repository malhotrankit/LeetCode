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
    bool isPalindrome(ListNode* head) 
    {
        int n,count=0;
        ListNode *ptr1, *ptr2, *ptr3;
        ptr1=head;
        while(ptr1!=NULL)
        {
            count++;
            ptr1=ptr1->next;
        }
        n=count;
        count=count/2;
        ptr1=NULL;
        ptr2=head;
        ptr3=head;
        while(count)
        {
            ptr3=ptr3->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr3;
            count--;
        }
        if(n%2==1)
            ptr3=ptr3->next;
        while(ptr3!=NULL)
        {
            if(ptr1->val!=ptr3->val)
                return false;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        return true;
    }
};