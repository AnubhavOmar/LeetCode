// Solution of LeetCode POTD 
// 3658. GCD of Odd and Even Sums
// Solution in CPP

// Approach - 3
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum_of_odd = n * n;
        int  sum_of_numbers = (n * (n+1))  ;
        return gcd(sum_of_odd , sum_of_numbers - sum_of_odd);
    }
};

// Approach - 2 
class Solution2 {
public:
    int gcdOfOddEvenSums(int n) {
       if(n==1)
           return 1;
        int sumEven=0;
        int sumOdd=0;
        for(int i=1;i<n*2;i++)
        {
            if(i%2==0)
               sumEven+=i;
            else
                sumOdd+=i;
        } 
        return gcd(sumEven , sumOdd);
    }
};

// Approach - 1
class Solution1 {
public:
    int gcdOfOddEvenSums(int n) {
        return n ;
    }
};