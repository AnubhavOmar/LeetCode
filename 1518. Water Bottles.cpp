// Solution of LeetCode Problem 
// 1518. Water Bottles 
// Solution in CPP 

// Approach - 1 (Brute Force) 

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0;
        int emptybottles = 0;
        while (numBottles > 0) {
            numBottles--;
            drank++;
            emptybottles++;
            if (emptybottles == numExchange) {
                numBottles++;
                emptybottles = 0;
            }
        }
        return drank;
    }
};

// Approach - 2 (Optimal Approach) 

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0 ;
        int empty = 0 ; 
        while(numBottles>0)
        {
            drank = drank + numBottles ;
            empty += numBottles ;
            numBottles = int(empty/numExchange);
            empty = empty % numExchange;
        }
        return drank;
    }
};