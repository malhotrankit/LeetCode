class Solution 
{
public:
    vector<string> v;
    int open,close,i;
    char s[16];
    
    inline void permutations(int open, int close, int i)
    {
        if(open==0&&close==0)
            v.push_back(s);
        else
        {
            if(open>0)//if(open<=close&&open>0)
            {
                s[i]='(';
                
                ++i;--open;
                
                permutations(open,close,i);
                
                --i;++open;
            }
            if(open<close&&close>0)
            {
                
                s[i]=')';
                
                ++i;--close;
                
                permutations(open,close,i);
                
                --i;++close;
                
            }
        }
    }
    
    inline vector<string> generateParenthesis(int n) 
    {
        permutations(n,n,0);
        return v;
            
    }
};