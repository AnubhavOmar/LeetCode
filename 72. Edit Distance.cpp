// Solution of LeetCode Problem
// 72. Edit Distance
// Solution in CPP

// Approach - 1
// Using Recursion with Memoization
// Time Complexity: O(M * N) - Store the answer for each pair of positions in the two words
// Space Complexity: O(M * N) - Memo table and recursive call stack use this space


// Recursion Based in which we are exploring all the operations and then coming to an conclusion
// Recursion + Memoization 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()  ;
        int n = word2.size()  ;
        
        vector<vector<int>>dp ( m , vector<int>( n , -1)) ;

        return helper( m - 1 , n - 1 , word1 , word2 , dp ) ;
    }

    int helper(int i ,  int j , string & s1 , string & s2 ,  vector<vector<int>> &dp ) 
    {
        // Base Case 
        if(i < 0 ) return j + 1 ; // Inserting remaining Character's of S2
        if(j < 0 ) return i + 1 ; // Inserting remaining Character's of S1

        if(dp[i][j] != -1) return dp[i][j] ;        

        // if same characters so skipping both index's  
        if(s1[i] == s2[j])
        {
            dp[i][j] = helper(i - 1 , j - 1 , s1 , s2 , dp ) ; 
        
            return dp[i][j] ;
        }
        // as we knwo three operations are there so three call's

        // replace
        int replace = 1 + helper( i - 1 , j - 1 , s1 , s2 , dp ) ;

        // remove
        int remove = 1 + helper( i - 1 , j , s1 , s2 , dp ) ;
        
        // insert
        int insert = 1 + helper( i , j - 1 , s1 , s2 , dp ) ;

        // taking minimum of all three operations beacsue we need minimum operation
        
        dp[i][j] = min(replace , min(insert , remove ) ) ;

        return dp[i][j] ;
    }

};


// Approach - 2
// Using Plain Recursion
// Time Complexity: O(3^(M + N)) - Try insert, remove, and replace at each different pair of positions
// Space Complexity: O(M + N) - Recursive call stack can reach the combined length of both words

// Recursion Based in which we are exploring all the operations and then coming to an conclusion
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() - 1 ;
        int n = word2.size() - 1 ;

        return helper( m , n , word1 , word2) ;
    }

    int helper(int i ,  int j , string & s1 , string & s2) 
    {
        // Base Case 
        if(i < 0 ) return j + 1 ; // Inserting remaining Character's of S2
        if(j < 0 ) return i + 1 ; // Inserting remaining Character's of S1
        
        // if same characters so skipping both index's  
        if(s1[i] == s2[j])
        {
            return helper(i - 1 , j - 1 , s1 , s2) ;
        }
        // as we knwo three operations are there so three call's

        // replace
        int replace = 1 + helper( i - 1 , j - 1 , s1 , s2) ;

        // remove
        int remove = 1 + helper( i - 1 , j , s1 , s2) ;
        
        // insert
        int insert = 1 + helper( i , j - 1 , s1 , s2) ;

        // taking minimum of all three operations beacsue we need minimum operation
        return min(replace , min(insert , remove ) ) ;
    }
};