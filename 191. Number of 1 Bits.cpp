// Solution of LeetCode Problem 
// 191. Number of 1 Bits
// Soltuion in CPP 

// Appraoch - 1 
// Time Complexity : O(logn)

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        while(n!= 0)
        {
            if(n%2==1)
            {
                count++;
            }
            n /= 2;
        }
        return count ;
    }
};