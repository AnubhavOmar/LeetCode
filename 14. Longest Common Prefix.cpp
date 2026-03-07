// Solution of LeetCode Problem 
// 14. Longest Common Prefix 
// Solution in  CPP 

// Approach - 1  
// Time Complexity = O(n * m) 
// Space Complexity = O(m) 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.size() == 1 ) return strs[0]; 
       string common = "" ; 
       for(int i = 0 ; i<strs.size() - 1 ; i++ )
       {
            string fun = check_common(strs[i] , strs[i+1]);
            if(fun.size() == 0) return "" ;
            if(common.size() == 0 ) common = fun ;
            else 
            {
                common = check_common(common , fun) ; 
            }    
       }
       return common ;
    }
    private :  
        string check_common(string a , string b)
        {
            string  comm = "" ;
            int i = 0 ;
            int j = 0 ; 
            while(i<a.size() && j <b.size())
            {
                if(a[i] != b[j])
                {
                    break ;
                }
                comm += a[i];
                i++;
                j++;
            }
            return comm ;
        }
};


// Approach - 2 
// Shrinking the Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            string fun = check_common(common , strs[i]);
            common = fun;

            if(common == "") return "";
        }

        return common;
    }

private:
    string check_common(string a , string b)
    {
        string comm = "";
        int i = 0;

        while(i < a.size() && i < b.size())
        {
            if(a[i] != b[i]) break;

            comm += a[i];
            i++;
        }

        return comm;
    }
};