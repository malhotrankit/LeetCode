class Solution {
public:
    bool isValid(string s) 
    {
        char stack[10001];
        int len, count=0, i;
        len = s.length();
        if(len%2==1)
            return false;
        else
        {
            for(i=0; i<len; i++)
            {
                if(s[i]=='('||s[i]=='['||s[i]=='{')
                    stack[count++] = s[i];
                else
                {
                    if(s[i]==')'&&count>0&&stack[count-1]=='(')
                        count--;
                    else if(s[i]==']'&&count>0&&stack[count-1]=='[')
                        count--;
                    else if(s[i]=='}'&&count>0&&stack[count-1]=='{')
                        count--;
                    else
                        break;
                }
            }
            if(i==len&&count==0)
                return true;
            else
                return false;
        }
    }
};