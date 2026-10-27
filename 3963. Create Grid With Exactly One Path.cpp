// Solution of LeetCode Problem
// 3963. Create Grid With Exactly One Path
// Solution in CPP

// Approach - 1
// Using Direct Grid Construction
// Time Complexity: O(mn) - Initializing the grid visits every cell, while opening the path takes O(m + n).
// Space Complexity: O(mn) - The returned grid stores m*n characters.

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        
        for(int j = 0 ; j < m ; j++)
        {
            grid[j][0] = '.';
        }

        for(int i = 1 ; i < n ;i++)
        {
            grid[m-1][i] = '.' ;
        }
        return grid ;
    }
};