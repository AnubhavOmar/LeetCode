// Solution of LeetCode POTD
// 3612. Process String with Special Operations I
// Solution in CPP

// Approach - 1 

class Solution {
public:
    string processStr(string s) {
        string result = "" ;
        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i] ;
            if(ch >= 'a' && ch <= 'z')
            {
                result.push_back(ch);
            }
            else if(ch == '#' && result.size() != 0)
            {
                result += result ;
            }
            else if(ch == '%')
            {
                reverse(result.begin(),result.end());
            }
            else if(ch == '*' && result.size() != 0)
            {
                result.pop_back();
            }
        }
        return result ;
    }
};