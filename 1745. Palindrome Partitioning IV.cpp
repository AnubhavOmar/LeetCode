// Solution of LeetCode Problem
// 1745. Palindrome Partitioning IV
// Solution in CPP

// Approach - 1
// Using Memoization to Check Palindromes
// Time Complexity: O(N^2) - Store the result of each substring check and try all split points
// Space Complexity: O(N^2) - The memo table stores results for all substrings

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        vector<vector<char>> P(n, vector<char>(n, -1));

        for (int i1 = 1; i1 < n - 1; i1++)
        {

            if (isPal(s, 0, i1 - 1, P) == false)
                continue;

            for (int i2 = i1 + 1; i2 < n; i2++)
            {

                if (isPal(s, i1, i2 - 1, P) && isPal(s, i2, n - 1, P))
                    {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool isPal(string& s, int i, int j, vector<vector<char>>& P) {

        if (j - i + 1 <= 1)
            return true;

        if (P[i][j] != -1)
            return P[i][j];

        P[i][j] = (s[i] == s[j]) && isPal(s, i + 1, j - 1, P);

        return P[i][j];
    }

    bool isPal_iterative(string& s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};

// Approach - 2
// Using Brute Force and Two Pointers
// Time Complexity: O(N^3) - Try all pairs of cuts and check each part in linear time
// Space Complexity: O(N) - The input string is passed by value and helper variables use constant extra space

class Solution2 {
public:
    bool checkPartitioning(string s)
    {
        int n = s.size() ;
        for(int i = 0 ; i < n - 2 ;i++)
        {
            if(is_palindrome(s , 0 , i))
            {
                for(int j = i + 1 ; j < n - 1 ;j++)
                {
                    if(is_palindrome(s, i + 1, j) && is_palindrome(s, j + 1, n - 1))
                    {
                        return true;
                    }
                }
            }
        }
        return false ;
    }

    bool is_palindrome(string & s , int i , int j )
    {
        while(i < j)
        {
            if(s[i] != s[j]) return false ;
            i++ ;
            j-- ;
        }
        return true; 
    }
};

// Approach - 3
// Using Brute Force and Two Pointers
// Time Complexity: O(N^3) - Try all pairs of cuts and check each part in linear time
// Space Complexity: O(N) - The input string is passed by value and helper variables use constant extra space

class Solution1 {
public:
    bool checkPartitioning(string s) {
        int n = s.size() ;
        for(int i1 = 1 ; i1 < n - 1 ; i1++)
        {
            // if the first subarray is not palindrome so dont check for others
            if( is_palindrome(s , 0 , i1 - 1 ) == false ) continue ;

            for(int i2 = i1 + 1 ; i2 < n ; i2++)
            {
                if( is_palindrome(s , i1 , i2-1) && is_palindrome(s , i2 , n -1 ) )
                {
                    return true; 
                }
            }
        }
        return false ;
    }

    bool is_palindrome(string & s , int i , int j )
    {
        while(i < j)
        {
            if(s[i] != s[j]) return false ;
            i++ ;
            j-- ;
        }
        return true; 
    }
};