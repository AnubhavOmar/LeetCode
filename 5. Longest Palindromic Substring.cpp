// Solution of LeetCode Problem
// 5. Longest Palindromic Substring
// Solution in CPP

// Approach - 1
// Using Depth-First Search (DFS) Substring Traversal
// Time Complexity: O(N^3) - Exploring substrings recursively and checking each for palindrome in linear time
// Space Complexity: O(N) - Recursive call stack space proportional to the string length N

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1 ) return s ;
        string ans = "";
        dfs(s, 0, ans);
        return ans;
    }

    void dfs(string& s, int i, string& ans)
    {
        int n = s.size();

        if (i == n)
            return;

        for(int j = i  ; j < n ; j++)
        {
            if(is_palindrome(s , i , j) && ans.size() < j - i + 1)
            {
                ans = s.substr( i , j - i + 1 );
            }
        }
        dfs(s, i + 1, ans);
    }

    bool is_palindrome(string& s, int i, int j)
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
// Using Expand Around Center
// Time Complexity: O(N^2) - Expanding around each character and between pairs of characters as centers in the string of size N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            string odd = odd_palindrome(s, i , i);

            if(odd.size() > ans.size())
            {
                ans = odd;
            }

            if(i + 1 < n)
            {
                string even = even_palindrome(s, i, i + 1);

                if(even.size() > ans.size())
                {
                    ans = even;
                }
            }
        }

        return ans;
    }

    string odd_palindrome(string &s, int left, int right)
    {
        string ans = "";

        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            if(ans.size() < right - left + 1)
            {
                ans = s.substr(left, right - left + 1);
            }

            left--;
            right++;
        }

        return ans;
    }

    string even_palindrome(string &s, int left, int right)
    {
        string ans = "";

        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            if(ans.size() < right - left + 1)
            {
                ans = s.substr(left, right - left + 1);
            }

            left--;
            right++;
        }

        return ans;
    }
};


// Approach - 3
// Using Brute Force Substring Enumeration and Palindrome Check
// Time Complexity: O(N^3) - Checking all possible substrings and verifying each palindrome in linear time
// Space Complexity: O(1) - Constant auxiliary space used

class Solution1 {
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