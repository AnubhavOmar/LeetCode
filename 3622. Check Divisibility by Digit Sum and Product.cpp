// Solution of LeetCode Problem
// 3622. Check Divisibility by Digit Sum and Product
// Solution in CPP

// Approach - 1
// Using Digit Extraction and Modular Arithmetic
// Time Complexity: O(log10(N)) - Number of digits in the integer N, as we process each digit once
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    bool checkDivisibility(int n) {
        int number = n ;
        int sum = 0 ; 
        int product = 1 ;
        while(n != 0)
        {
            sum += n % 10 ;
            product *= n % 10 ;
            n /= 10 ;
        }

        if(number % (sum + product) == 0)
        {
            return true;
        }
        return false;
    }
};