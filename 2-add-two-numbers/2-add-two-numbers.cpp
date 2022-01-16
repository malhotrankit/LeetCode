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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *tail1,*tail2,*addNode;
        addNode = new ListNode(1);
        //addNode->val= 1;
        //addNode->next = NULL;
        int len1=0, len2=0, carry=0;
        tail1 = l1;
        tail2 = l2;
        while(tail1!=NULL)
        {
            len1++;
            tail1=tail1->next;
        }
        while(tail2!=NULL)
        {
            len2++;
            tail2=tail2->next;
        }
        tail1= l1;
        tail2= l2;
        if(len1>=len2)
        {
            while(tail2!=NULL)
            {
                tail1->val = tail1->val + tail2->val + carry;
                if(tail1->val>9)
                {
                    carry = tail1->val / 10;
                    tail1->val = tail1->val % 10;
                }
                else
                    carry = 0;
                tail1 = tail1->next;
                tail2 = tail2->next;
            }
            if(carry!=0)
            {
                if(tail1!=NULL)
                {
                    while(carry!=0)
                    {
                    
                        tail1->val = tail1->val + carry;
                        if(tail1->val>9)
                        {
                            carry = tail1->val / 10;
                            tail1->val = tail1->val % 10;
                        }
                        else
                            carry = 0;
                        if(tail1->next==NULL&&carry!=0)
                        {
                            tail1->next = addNode;
                            break;
                        }
                        tail1 = tail1->next;
                    }
                }
                else
                {
                    tail1 = l1;
                    while(tail1->next!=NULL)
                    {
                        tail1 = tail1->next;
                    }
                    tail1->next = addNode;
                }
            }
        }
        else
        {
            while(tail1!=NULL)
            {
                tail2->val = tail2->val + tail1->val + carry;
                if(tail2->val>9)
                {
                    carry = tail2->val / 10;
                    tail2->val = tail2->val % 10;
                }
                else
                    carry = 0;
                tail1 = tail1->next;
                tail2 = tail2->next;
            }
            if(carry!=0)
            {
                if(tail2!=NULL)
                {
                    while(carry!=0)
                    {
                    
                        tail2->val = tail2->val + carry;
                        if(tail2->val>9)
                        {
                            carry = tail2->val / 10;
                            tail2->val = tail2->val % 10;
                        }
                        else
                            carry = 0;
                        if(tail2->next==NULL&&carry!=0)
                        {
                            tail2->next = addNode;
                            break;
                        }
                        tail2 = tail2->next;
                    }
                }
                else
                {
                    tail2 = l2;
                    while(tail2->next!=NULL)
                    {
                        tail2 = tail2->next;
                    }
                    tail2->next = addNode;
                }
            }
            return l2;
        }
        return l1;
        
    }
};