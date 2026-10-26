// Solution of LeetCode Problem
// 3619. Count Islands With Total Value Divisible by K
// Solution in CPP

// Approach - 1
// Using Depth-First Search (DFS) to Find Island Sums
// Time Complexity: O(M * N) - Each grid cell is visited at most once
// Space Complexity: O(M * N) - Recursive call stack and stored island sums can use this space

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<long long> island_sum ;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] != 0)
                {
                    long long sum = 0 ;
                    find_island_sum(i , j , sum , grid);
                    island_sum.push_back(sum) ;
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < island_sum.size(); i++)
        {
            if(island_sum[i] % k == 0)
            {
                ans++;
            }
        }
        return ans;
    }
    void find_island_sum(int i , int j , long long & sum , vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return ;
        }

        sum += grid[i][j] ;

        grid[i][j] = 0 ;

        find_island_sum(i + 1 , j , sum , grid) ;
        find_island_sum(i - 1 , j , sum , grid) ;
        find_island_sum(i , j + 1 , sum , grid) ;
        find_island_sum(i , j - 1 , sum , grid) ;
        

    }
};