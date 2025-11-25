// Solution of LeetCode problem 
// 1015. Smallest Integer Divisible by K 

// Optimal Appraoch 

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int old_value = 1 % k;
        if (old_value == 0) return 1;   

        for (int i = 1; i <= k; i++)    
        {
            old_value = ((old_value * 10) + 1) % k;
            if (old_value == 0)
            {
                return i + 1;
            }
        }

        return -1;
    }
};