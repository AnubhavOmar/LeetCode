// Solution of LeetCode Problem 
// 3222. Find the Winning Player in Coin Game
// Solution in CPP

// Approach - 2 

class Solution {
public:
    string winningPlayer(int x, int y) {
        int count = min( x / 1 , y / 4 );
        return count % 2 != 0 ? "Alice" : "Bob" ;
    }
};

// Approach - 1

class Solution1 {
public:
    string winningPlayer(int x, int y) {
        int count = 0 ;
        while(x >= 1 && y >= 4)
        {
            count++;
            x -= 1 ;
            y -= 4 ;
        }
        
        return count % 2 != 0 ? "Alice" : "Bob" ;
    }
};