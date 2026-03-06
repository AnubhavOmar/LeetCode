// Solution of LeetCode POTD 
// 1784. Check if Binary String Has at Most One Segment of Ones
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    bool checkOnesSegment(string s) {
       int start = -1 ;
       for(int i = 1 ; i<s.size() ; i++)
       {
            if(s[i] == '0')
            {
                start = i ;
                break ;
            }
       }
        for(int j = start ; j<s.size();j++)
        {
            if(s[j] == '1')
            {
                return false;
            }
        }
        return true ;
    }
};