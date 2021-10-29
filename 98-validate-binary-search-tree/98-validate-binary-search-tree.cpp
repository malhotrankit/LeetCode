/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<int> v;
    inline bool isValidBST(TreeNode* root) 
    {
        int i;
        isValid(root);
        for(i=1;i<v.size();i++)
            if(v[i-1]>=v[i])
                break;
        //for(i=0;i<v.size();i++)
            //printf("%d ",v[i]);
        if(i==v.size())
            return true;
        else
            return false;
        
    }
    
    inline void isValid(TreeNode* root)
    {
        if(root==NULL)
            return;
        isValid(root->left);
        v.push_back(root->val);
        isValid(root->right);
    }
    
    
};