/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{ 
    private: vector<int>v;
    public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<int> v;
        int n,i;
        v=createV(root);
        //sort(v.begin(),v.end());
        n = v.size();
        /*for(i=0;i<n;i++)
            printf("%d ",v[i]);*/
        //if(NULL==0)
            //printf("a");
        //free(root);
        
        TreeNode *root2 = (TreeNode*)malloc(sizeof(TreeNode));
        root2->left=NULL;
        TreeNode *first;
        TreeNode *tail;
        for(i=0;i<n;i++)
        {
            //if(v[i]!=NULL)
            //{
                root2->val=v[i];
                break;
            //}
        }
        first=root2;
        tail=root2;
        ++i;
        for(;i<n;i++)
        {
            //if(v[i]!=NULL)
            //{
                first = (TreeNode*)malloc(sizeof(TreeNode));
                first->val=v[i];
                first->left=NULL;
                tail->right=first;
                tail=tail->right;
            //}
        }
        tail->right=NULL;
        first=first->right;
        tail=tail->right;
        delete tail;
        delete first;
        return root2;
            
    }
    std::vector<int> createV(TreeNode* root)
    {
        if(root!=NULL)
        {
            createV(root->left);
            v.push_back(root->val);
            createV(root->right);
        }
        return v;        
    }
};