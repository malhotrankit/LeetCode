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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *ptr1, *ptr2;
        int count1=1 , count2=1;
        ptr2= head;
        ptr1= head;
        while(ptr2->next!=NULL)
        {
            count2++;
            ptr2=ptr2->next;
            if(count2%2==0)
            {
                ptr1=ptr1->next;
                count1++;
            }
            
        }
        return ptr1;
    }
};