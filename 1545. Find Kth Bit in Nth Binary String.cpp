// Solution of LeetCode POTD 
// 1545. Find Kth Bit in Nth Binary String
// Solution in CPP 

// Appraoch - 1 (Using Recurssion)

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int mid = 1 << (n - 1);   // 2^(n-1)

        if(k == mid) 
            return '1';

        else if(k < mid) 
            return findKthBit(n - 1, k);

        else {
            char ans = findKthBit(n - 1, (1 << n) - k);
            return (ans == '0') ? '1' : '0';   // invert the bits 
        }
    }
};