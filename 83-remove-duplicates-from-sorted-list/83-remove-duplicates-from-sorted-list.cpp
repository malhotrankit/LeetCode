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
        set<int> check;
        ListNode *tail, *back, *forward;
        tail=head;
        while(tail!=NULL)
        {
            if(!check.empty()&&(*(--check.end())==tail->val))
            {
                back->next=forward;
                delete tail;
                tail=forward;
                if(forward!=NULL)
                    forward=forward->next;
            }
            else
            {
                check.insert(tail->val);
                back = tail;
                tail = tail->next;
                if(tail!=NULL)
                    forward = tail->next;
            }
            
            
        }
        return head;
    }
    
};