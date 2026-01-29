// Solution of LeetCode Problem 
// 2027. Minimum Moves to Convert String
// Solution in CPP 

// Appraoch - 1 

class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                ans++;
                i += 2; 
            }
        }

        return ans;
    }
};
