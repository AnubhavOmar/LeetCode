// Solution of LeetCode Problem
// 1342. Number of Steps to Reduce a Number to Zero 
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int numberOfSteps(int num) {
       if(num == 0 ) return 0 ; 
       int count =0 ; 
       while (num != 0)
       {
        if(num % 2 ==0)  num = num /2 ;
        else num -= 1 ;
        count++;
       }
       return count ;
    }
};
 
