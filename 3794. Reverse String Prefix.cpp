// Solution of LeetCode Problem
// 3794. Reverse String Prefix
// Solution in CPP

// Approach - 1

class Solution {
public:
    string reversePrefix(string s, int k) {
        string ans = "" ;
        for(int i = k - 1 ; i >= 0 ; i--)
        {
            ans += s[i];
        }
        for(int i = k ; i < s.size() ; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};
