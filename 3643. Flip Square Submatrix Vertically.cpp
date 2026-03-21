// Solution of LeetCode POTD 
// 3643. Flip Square Submatrix Vertically
// Solution in CPP 



// Approach - 1  (Time Complexity : K^2)

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int top = x ;
        int bottom = x + k - 1 ; 

        while( top < bottom)
        {
            // top row ke har column ko bottom row ke same column se swap kar rhe hai
            for(int column = y ; column < y + k   ; column++  )
            {
                swap(grid[top][column] , grid[bottom][column]) ;
            }
            top++ ;
            bottom-- ;
        }
        return grid ;
    }
};