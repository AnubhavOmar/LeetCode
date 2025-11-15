// Solution of LeetCode problem 
// 231. Power of Two

// Optimal approach
class Solution {
public:
    bool isPowerOfTwo(int n) {
              return n > 0 && (n & (n - 1)) == 0;
    }
};

// Brute force 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1) return true;
        if (n<=1) return false;
        for (int i = 0; i <= sqrt(n) + 1; i++) {
            if (pow(2, i) == n) {
                return true;
            }
        }
        return false;
    }
};