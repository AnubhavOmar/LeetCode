// Solution of LeetCode Problem
// 1143. Longest Common Subsequence
// Solution in CPP

// ================================================================
//                         LEETCODE
//                 1143. Longest Common Subsequence
// ================================================================

// Approach - 1
// Using Recursion with Memoization
// Time Complexity: O(M * N) - Store and reuse results for every pair of positions in both strings
// Space Complexity: O(M * N) - Use a memo table and a recursive call stack

// Recursion + Memoization

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // we can start from both start or end places of string
        int m = text1.size() ;
        int n = text2.size() ;

        vector<vector<int>>dp ( m + 1 , vector<int> (n,-1)) ;

        return helper( text1.size() - 1 , text2.size() - 1 , text1 , text2 , dp );
    }
    int helper(int i , int j , string & s1 , string &s2 , vector<vector<int>> & dp)
    {
        if(i < 0 || j < 0)
        {
            return 0 ;
        }
        if(dp[i][j] != -1) return dp[i][j] ;

        if(s1[i] == s2[j])
        {
            dp[i][j] = 1 + helper(i - 1, j - 1 , s1 , s2 , dp) ;
            return dp[i][j] ;
        }

        int s1_skip = helper( i - 1 , j , s1 , s2 , dp ) ;
        int s2_skip = helper( i , j - 1 , s1 , s2 , dp ) ;

        dp[i][j] = max(s1_skip , s2_skip) ; 
        return  dp[i][j] ;
    }
};



// Approach - 2
// Using Plain Recursion
// Time Complexity: O(2^(M + N)) - Try skipping characters from both strings and may revisit overlapping states
// Space Complexity: O(M + N) - Recursive call stack depth follows the two string positions

// Recursion 
class Solution1 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // we can start from both start or end places of string
        return helper( text1.size() - 1 , text2.size() - 1 , text1 , text2 );
    }
    int helper(int i , int j , string & s1 , string &s2)
    {
        if(i < 0 || j < 0)
        {
            return 0 ;
        }
        if(s1[i] == s2[j])
        {
            return 1 + helper(i - 1, j - 1 , s1 , s2) ;
        }

        int s1_skip = helper( i - 1 , j , s1 , s2) ;
        int s2_skip = helper( i , j - 1 , s1 , s2) ;

        return max(s1_skip , s2_skip) ;
    }
};

// ================================================================
//                           GFG
//                 Longest Common Subsequence
// ================================================================

// Approach - 3
// Using Recursion with Memoization
// Time Complexity: O(M * N) - Store and reuse results for every pair of positions in both strings
// Space Complexity: O(M * N) - Use a memo table and a recursive call stack

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // we can start from both start or end places of string
        int m = s1.size() ;
        int n = s2.size() ;

        vector<vector<int>>dp ( m + 1 , vector<int> (n,-1)) ;

        return helper( 0 , 0 , s1 , s2 , dp );
    }
    int helper(int i , int j , string & s1 , string &s2 , vector<vector<int>> & dp)
    {
        if(i >= s1.size() || j >= s2.size() )
        {
            return 0 ;
        }
        
        if(dp[i][j] != -1) return dp[i][j] ;

        if(s1[i] == s2[j])
        {
            dp[i][j] = 1 + helper(i + 1, j + 1 , s1 , s2 , dp) ;
            return dp[i][j] ;
        }

        int s1_skip = helper( i + 1 , j , s1 , s2 , dp ) ;
        int s2_skip = helper( i , j + 1 , s1 , s2 , dp ) ;

        dp[i][j] = max(s1_skip , s2_skip) ; 
        return  dp[i][j] ;
    }
};


// Approach - 4
// Using Plain Recursion
// Time Complexity: O(2^(M + N)) - Try skipping characters from both strings and may revisit overlapping states
// Space Complexity: O(M + N) - Recursive call stack depth follows the two string positions

class Solution1 {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        return helper(0 , 0 , s1 , s2) ;
    }
    
    int helper(int i  , int j , string &s1, string &s2)
    {
        if( i >= s1.size() || j >= s2.size()) return 0 ;
        if(s1[i] == s2[j]) return 1 + helper(i + 1 , j + 1 , s1 , s2);
        
        int s1_skip = helper(i + 1, j , s1 , s2);
        int s2_skip = helper(i , j + 1 , s1 , s2);
        return max(s1_skip , s2_skip);
    }
    
};
