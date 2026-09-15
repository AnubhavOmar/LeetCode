// Solution of LeetCode Problem
// 5. Longest Palindromic Substring
// Solution in CPP

// Approach - 1
// Using Brute Force Substring Enumeration and Palindrome Check
// Time Complexity: O(N^3) - Checking all possible substrings and verifying each palindrome in linear time
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size() ;
                
        string ans = "" ;
        
        for(int i = 0 ; i <  n  ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                if(is_palindrome(s , i , j) && ans.size() < j - i + 1)
                {
                    ans = s.substr(i , j - i + 1) ;
                }
            }
        }

        return ans;
    }
    bool is_palindrome(string & s , int i , int j )
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++ ;
            j--;
        }
        return true;
    }
};