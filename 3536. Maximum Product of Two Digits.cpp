// Solution of LeetCode POTD
// 3536. Maximum Product of Two Digits
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int maxProduct(int n) {
        int first = -1;
        int second = -1;

        while (n) {
            int digit = n % 10;

            if (digit > first) {
                second = first;
                first = digit;
            }
            else if (digit > second) {
                second = digit;
            }

            n /= 10;
        }

        return first * second;
    }
};