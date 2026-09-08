// Solution of LeetCode Problem
// 3870. Count Commas in Range
// Solution in CPP

// Approach - 1
// Using Mathematical Formula
// Time Complexity: O(1) - Constant time calculation
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    int countCommas(int n) {
        if ( n < 1000) return 0 ;
        return n - 1000 + 1 ;
    }
};