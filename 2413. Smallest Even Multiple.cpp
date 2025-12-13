// Solution of LeetCode Problem 
// 2413. Smallest Even Multiple 
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return ((n % 2)==0) ? n : n*2 ; 
    }
};