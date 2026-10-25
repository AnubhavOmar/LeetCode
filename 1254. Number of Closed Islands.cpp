// Soluton of LeetCode POTD
// 1254. Number of Closed Islands
// Solution in CPP

// Approach - 1
// Using DFS to Collect Islands and Check Boundary Connectivity
// Time Complexity: O(mn) - Each cell is visited during island discovery and checked at most once with four directions.
// Space Complexity: O(mn) - The stored islands and recursion stack can require O(mn) space.

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        // in this first we are finding all the islands 

        vector<vector<pair<int,int>>> all_island;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 0)
                {
                    vector<pair<int,int>> curr_island ;
                    find_connected_island( i , j , grid , curr_island );
                    all_island.push_back(curr_island);
                }
            }

        }

        int closed_island = 0 ;

        for(int i = 0 ; i < all_island.size() ; i++)
        {
            if(is_closed_island(all_island[i] , grid ))
            {
                closed_island++ ;
            }
        }

        return closed_island ;
    }
    void find_connected_island(int i , int j ,vector<vector<int>> & grid ,
                            vector<pair<int,int>> & curr_island )
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            // out of bound
            return ;
        }
        if(grid[i][j] == -1 || grid[i][j] == 1)
        {
            // already connected island and water conditon if found taht so return 
            return ;
        }
        
        // if this line u come it means that the this land is not connected to any island 
        // so making it visited
        grid[i][j] = -1;

        curr_island.push_back( {i , j} ) ;
        
        // up
        find_connected_island(i - 1 , j , grid , curr_island) ;

        // down
        find_connected_island(i + 1 , j , grid , curr_island) ;
        
        // left
        find_connected_island(i , j - 1 , grid , curr_island) ;

        // right
        find_connected_island(i , j + 1 , grid , curr_island) ;
    }

    bool is_closed_island(vector<pair<int,int>>& island , vector<vector<int>> & grid )
    {
        int n = island.size() ;
        // in this function we are checking that the given connected island pairs is closed_island or not we will do this by
        // we will check every land in grid that is that land is closed or not this will checked by another function i.e is_point_closed_island() ;

        for(int i = 0 ; i < n ; i++)
        {
            if( !is_point_closed_island( island[i].first , island[i].second  , grid ) )
            {
                return false ;
            }
        }
        
        return true; // i.e all connected island are closed island i.e they are  surrounded by 1 ;
    }

    bool is_point_closed_island(int x , int y , vector<vector<int>> & grid)
    {
        vector<pair<int,int>>direction = {
            { 0 , -1 } , { 0 , 1 },
            { -1 , 0 } , { 1 , 0 } , 
        };
        for(int i = 0 ; i < direction.size() ; i++)
        {
            int new_x = x + direction[i].first ;
            int new_y = y + direction[i].second ;
            if( new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() )
            {
                return false; 
            }
        }
        return true; 
    }

};