// Solution of LeetCode Problem 
// 3798. Largest Even Number 
// Solution in cpp 

// Approach 1 

class Solution {
public:
    string largestEven(string s) {
        int n = s.size() ;
        int idx = -1 ;
        for(int i = n -1 ; i>=0;i--)
        {
            int d = s[i] - '0';
            if(d%2==0)
            {
                idx = i;
                break ;
            }
        }
        string ans = "";
        for(int i = 0 ;i<=idx;i++)
        {
            ans += s[i];
        }
        return ans;

    }
};

// same Approach 1 but make only rem