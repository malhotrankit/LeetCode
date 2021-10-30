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
    vector<TreeNode*> generateTrees(int n) 
    {
        return genTree(1,n);
    }
    vector<TreeNode*> genTree(int begin, int end)
    {
        vector<TreeNode*> ans;
        if(begin>end)
        {   
            return {}; 
        }
        if(begin==end)
        {
            return {new TreeNode(begin)};
        }
        for(int i=begin; i<=end; i++)
        {
            vector<TreeNode*> lt = genTree(begin,i-1);
            vector<TreeNode*> rt = genTree(i+1,end);
            for(int j=0;j<lt.size();j++)
            {
                for(int k=0; k<rt.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lt[j];
                    root->right = rt[k];
                    ans.push_back(root);
                }
            }
            if(lt.size()==0&&rt.size()!=0)
            {
                 for(int k=0; k<rt.size(); k++)
                 {
                    TreeNode* root = new TreeNode(i);
                    root->left = NULL;
                    root->right = rt[k];
                    ans.push_back(root);
                 }
            }
            if(rt.size()==0&&lt.size()!=0)
            {
                 for(int j=0; j<lt.size(); j++)
                 {
                    TreeNode* root = new TreeNode(i);
                    root->left = lt[j];
                    root->right = NULL;
                    ans.push_back(root);
                 }
                
            }
        }
        return ans;
    }
};