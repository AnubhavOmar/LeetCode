// Solution of LeetCode Problem
// 91. Decode Ways
// Solution in CPP

// Approach - 1
// Using Bottom-Up Dynamic Programming
// Time Complexity: O(n) - Processes each character once
// Space Complexity: O(n) - Stores results for each suffix in the DP array

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size() ;
        if(n == 0) return 0;
        
        vector<int> dp ( n + 1 , 0 ) ;

        dp[n] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                // What should happen?
                dp[i] = 0 ;
            }
            else
            {
                // One digit
                dp[i] = dp[i + 1];

                // Two digit condition
                if(i + 1 < n)
                {
                    int digit = (s[i] - '0') * 10 + (s[i + 1] - '0');

                    if(digit >= 10 && digit <= 26)
                    {
                        // Store answer in dp[i]
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};


// Approach - 2
// Using Recursion with Memoization
// Time Complexity: O(n) - Computes each index once, with constant work per index
// Space Complexity: O(n) - Stores memoized results and uses recursion stack space
class Solution1 {
public:
    int numDecodings(string s) {
        
        int n = s.size() ;

        vector<int> dp( n , -1 ) ;

        return helper(0 , s , dp) ;
    }
    int helper(int i , string & s , vector<int> & dp)
    {
        if(i == s.size() ) 
        {
            // valid case 
            return 1 ;
        }
        
        if(dp[i] != -1) return dp[i] ;

        if(s[i] == '0' )
        {
            dp[i] = 0 ;
            return dp[i] ;
        }

        int oneDigit = helper(i + 1, s , dp ) ;
        
        int twoDigit = 0 ;
        // Check if next character exists
        if (i + 1 < s.size())
        {
            int digit = ((s[i] - '0') * 10) + (s[i + 1] - '0');

            // Check valid pair: 10 to 26
            if (digit >= 10 && digit <= 26)
            {
                twoDigit = helper(i + 2, s , dp );
            }
        }

        dp[i] = oneDigit + twoDigit ;

        return dp[i] ;
    }
};

// Approach - 3
// Using Recursion
// Time Complexity: O(2^n) - Each position can branch into one- or two-digit decoding
// Space Complexity: O(n) - Recursion depth can reach n
class Solution2 {
public:
    int numDecodings(string s) {
        return helper(0 , s) ;
    }
    int helper(int i , string & s)
    {
        if(i == s.size() ) 
        {
            // valid case 
            return 1 ;
        }

        if(s[i] == '0' )
        {
            return 0 ;
        }

        int oneDigit = helper(i + 1, s) ;
        
        int twoDigit = 0 ;
        // Check if next character exists
        if (i + 1 < s.size())
        {
            int digit = ((s[i] - '0') * 10) + (s[i + 1] - '0');

            // Check valid pair: 10 to 26
            if (digit >= 10 && digit <= 26)
            {
                twoDigit = helper(i + 2, s);
            }
        }

        
        return oneDigit + twoDigit ;
    }
};