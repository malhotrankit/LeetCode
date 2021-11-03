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
    stack<int> st;
    vector<stack<int>> vv;
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0, i, n, j;
        sumTree(root);
        //printf("size = %d\n", vv.size());
        for(i=0;i<vv.size();i++)
        {
            j= 0;
            n= 0;
            while(!vv[i].empty())
            {
                n += vv[i].top() * pow(10, j);
                //printf("%d ", vv[i].top());
                vv[i].pop();
                j++;
            }
            sum += n;
            //printf("\n");
        }
        return sum;
    }
    void sumTree(TreeNode *root)
    {
        st.push(root->val);
        
        if(root->left!=NULL)
            sumTree(root->left);  
        
        if(root->right!=NULL)
            sumTree(root->right);
        
        if(root->right==NULL&&root->left==NULL)
            vv.push_back(st);
            
        st.pop();
    }
};