// Solution of LeetCode 
// 509. Fibonacci Number
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int a = 0 ; 
        int b = 1 ;
        int count = 2 ;
        while(count<=n)
        {
            int c = a + b ;
            a = b ;
            b = c ;
            count++;
        }
        return b;
    }
};