// Solution of LeetCode Problem 
// 1523. Count Odd Numbers in an Interval Range 
// Solution in CPP 

// Appraoch - 1 (Brute Force)

class Solution {
public:
    int countOdds(int low, int high) {
     int count = 0 ; 
     for(int i = low ; i<high +1 ; i++)
     {
        if(i %2 != 0) count++;
     }   
     return  count;
    }
};