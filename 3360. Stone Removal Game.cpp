// Solution of LeetCode Problem
// 3360. Stone Removal Game
// Solution in CPP

// Approach - 1
// Using Greedy Simulation
// Time Complexity: O(1) - The loop runs at most 10 times
// Space Complexity: O(1) - Uses a constant amount of extra space
class Solution {
public:
    bool canAliceWin(int n) {
        
        int remove = 10 ;
        bool alice = false ;
        while(n >= remove && remove > 0)
        {
            n -= remove ;
            remove-- ;
            alice = !alice;
        }
        return alice;
    }
};