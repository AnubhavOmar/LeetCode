// Solution of LeetCode Problem 
// 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0 ;i<s.size() ;i++)
        {
            if(s[i]=='?')
            {
               char st = 'a';
               for(char c = 'a' ; c <= 'c';c++)
               {
                if((i == 0 || s[i-1] != c) && (i == s.size()-1 || s[i+1] != c))
                {
                    s[i] = c;
                    break ;
                }
               }
            }
        }
        
        return s;
    }
};