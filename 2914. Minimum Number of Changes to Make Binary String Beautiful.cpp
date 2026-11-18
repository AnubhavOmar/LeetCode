// Solution of LeetCode Problem
// 2914. Minimum Number of Changes to Make Binary String Beautiful
// Solution in CPP

// Approach - 1
// Using Greedy Pair Checking
// Time Complexity: O(N) - Check each pair of characters once
// Space Complexity: O(1) - Use only a counter and loop variables

class Solution {
public:
    int minChanges(string s) {
        
        int ans = 0 ;
        
        int n  = s.size() ;
        
        for(int i = 1 ; i < n ; i += 2)
        {
            if(s[i] != s[i-1])
            {
                ans++;
            }
        }
        return ans;
    }
};