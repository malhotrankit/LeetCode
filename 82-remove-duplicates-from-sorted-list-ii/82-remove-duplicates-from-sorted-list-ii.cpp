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
class Solution 
{
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            ListNode *back, *tail, *forward;
            int array[202], count=0;
            tail=head;
            back=NULL;
            while(count!=201)
                array[count++]=0;
            while(tail!=NULL)
            {
                array[tail->val+100]++;
                tail=tail->next;
            }
            tail=head;
            head=NULL;
            count=0;
            while(tail!=NULL)
            {
                forward=tail->next;
                if(array[tail->val+100]>1)
                {
                   if(back!=NULL)
                        back->next=forward;
                    delete tail;
                    tail=forward;
                }
                else
                {
                    if(count==0)
                    {
                        head=tail;
                        count++;
                    }
                    back=tail;
                    tail=tail->next;
                }
            }
        return head;
        }
};