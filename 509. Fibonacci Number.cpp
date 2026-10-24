// Solution of LeetCode Problem
// 509. Fibonacci Number
// Solution in CPP

// Approach - 1
// Using Bottom-Up Dynamic Programming with Tabulation
// Time Complexity: O(n) - The DP table is filled from 2 through n.
// Space Complexity: O(n) - The DP table stores n + 1 Fibonacci values.

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0 ;
        if(n == 1) return 1 ;
        vector<int> dp(n + 1) ; // we take n + 1 ;
        dp[0] = 0 ;
        dp[1] = 1 ;
        for(int i = 2 ; i < dp.size() ; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] ;
        }
        return dp[n] ;
    }
};

// Approach - 2
// Using Top-Down Dynamic Programming with Memoization
// Time Complexity: O(n) - Each Fibonacci state is calculated once.
// Space Complexity: O(n) - The memoization array and recursion stack use linear space.

class Solution {
public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }

    int fibo(int n, vector<int>& dp)
    {
        if (n <= 1) return n;

        if (dp[n] != -1)
        {
            // result of call already exist in the dp array then return only that
            return dp[n];
        }

        // if the ans not in dp array so finding it and then storing it also
        int ans = fibo(n - 1, dp) + fibo(n - 2, dp);

        dp[n] = ans;  // here storing in dp array at nth position of it
        return ans;
    }
};

// Approach - 3
// Using Plain Recursion
// Time Complexity: O(2^n) - The recursive calls repeatedly recompute the same Fibonacci values.
// Space Complexity: O(n) - The recursion stack can reach depth n.

class Solution2 {
public :
    int fib(int n) {
        return fibo(n);
    }
    int fibo(int n) 
    {
        if(n <= 1) return n;
        return fibo(n-1) + fibo(n-2) ;
    }
};

// Approach - 4
// Using Iterative Approach with Constant Space
// Time Complexity: O(n) - The loop computes each Fibonacci value once.
// Space Complexity: O(1) - Only a constant number of variables are maintained.

class Solution1 {
public:
     int fib(int n) {
        if(n==0) return 0;
        int a = 0 ; 
        int b = 1 ;
        int count = 2 ;
        while(count<=n)
        {
            int c = a + b ;
            a = b ;
            b = c ;
            count++;
        }
        return b;
    }
};