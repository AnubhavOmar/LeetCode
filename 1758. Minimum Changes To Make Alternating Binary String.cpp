// Solution of LeetCode POTD 
// 1758. Minimum Changes To Make Alternating Binary String
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int minOperations(string s) {
        
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < s.size(); i++)
        {
            char p1 = (i % 2 == 0) ? '0' : '1';
            char p2 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != p1) count1++;
            if(s[i] != p2) count2++;
        }
        
        return min(count1, count2);
    }
};