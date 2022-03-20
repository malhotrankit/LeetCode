class Solution 
{
public:
    vector<string> vv;
    string str;
    int glen;
    char matrix[9][4]={{'.','.','.','.'},{'a','b','c','.'},{'d','e','f','.'},{'g','h','i','.'},{'j','k','l','.'},{'m','n','o','.'},{'p','q','r','s'},{'t','u','v','.'},{'w','x','y','z'}};
    
    inline void permutations(string digits, int slen, int j)
    {
        if(slen==glen)
        {
            vv.push_back(str);
            //cout<<str<<"\n";
        }
    
        if(slen<glen)
        {
            for(int j=0; j<4; j++)
            {
                if(matrix[digits[slen]-49][j]!='.')
                {
                    str.push_back(matrix[digits[slen]-49][j]);
                    ++slen;
                    
                    permutations(digits, slen, j);
                    
                    str.pop_back();
                    --slen;
                }
            }    
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        glen=digits.length();
        if(glen>0)
            permutations(digits, 0, 0);
        return vv;
    }
};