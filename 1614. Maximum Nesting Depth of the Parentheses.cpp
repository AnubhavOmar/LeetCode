// Solution of LeetCode POTD
// 1614. Maximum Nesting Depth of the Parentheses
// Solution in CPP 

// Approach  - 1
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN ;
        int count = 0 ; 
        int n = s.size() ; 
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')
            {
                count++ ;
            }
            else if(s[i] == ')' )
            {
                ans = max(count , ans) ;
                count--;
            }
        }
        return ans ==  INT_MIN ? 0 : ans;
    }
};