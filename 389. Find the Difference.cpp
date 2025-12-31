// Solution of Leetcode Problem 
// 389. Find the Difference 
// Solution in CPP 

// Approach - 1 

#include <map>
class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0)
            return t[0];
        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            m2[t[i]]++;
        }

        for (auto a : m2) {

            if (m1[a.first] != a.second) {
                return a.first;
            }
        }
        return 0;
    }
};