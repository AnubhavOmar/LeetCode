// Solution of LeetCode POTD 
// 1189. Maximum Number of Balloons
// Solution in CPP 

// Approach - 1

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> ump;

        int n = text.size();
        for (int i = 0; i < n; i++) {
            ump[text[i]]++;
        }
        int ans = INT_MAX;
        for (auto a : ump) {
            ans = min(ans , ump['b']);
            ans = min(ans , ump['a']);
            ans = min(ans , ump['l'] / 2 );
            ans = min(ans , ump['o'] / 2 );
            ans = min(ans , ump['n']);
        }
        return ans;
    }
};