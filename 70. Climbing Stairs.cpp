// Solution of LeetCode Problem
// 70. Climbing Stairs
// Solution in CPP

// Approach - 1
// Using Dynamic Programming (Tabulation)
// Time Complexity: O(N) - Fill the DP array from 3 to N
// Space Complexity: O(N) - Store answers for all stair counts in a DP array

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n ;
        vector<int>dp(n + 1, -1 );
        dp[0] = 0 ;
        dp[1] = 1 ;
        dp[2] = 2 ;

        for(int i = 3 ; i <= n ; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] ;
        }

        return dp[n] ; 
    }
};

// Approach - 2
// Using Dynamic Programming (Memoization) with Recursion
// Time Complexity: O(N) - Each stair count is calculated only once
// Space Complexity: O(N) - DP array and recursive call stack use linear space

class Solution2 {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1 , -1 );

        return helper(n  , dp) ; 
        
    }
    int helper(int n , vector<int> &dp)
    {
        if(n == 2) return n ;
        if(n == 1) return n ;
        if(dp[n] != -1) return dp[n] ;

        dp[n] = helper(n - 1 , dp) + helper(n - 2 , dp) ;

        return dp[n] ;
    }
};


// Approach - 3
// Using Plain Recursion
// Time Complexity: O(2^N) - Repeatedly solve the same smaller stair-count problems
// Space Complexity: O(N) - Recursive call stack can reach depth N

class Solution1 {
public:
    int climbStairs(int n) {
        if(n == 2) return n ;
        if(n == 1) return n ;
        return climbStairs(n - 1) + climbStairs(n - 2) ;
    }
};