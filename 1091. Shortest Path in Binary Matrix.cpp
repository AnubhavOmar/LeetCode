// Solution of LeetCode Problem
// 1091. Shortest Path in Binary Matrix
// Solution in CPP

// Approach - 1
// Using Breadth-First Search with Level Tracking and a Set
// Time Complexity: O(RC log(RC)) - Each cell is processed once, and set operations take O(log(RC)).
// Space Complexity: O(RC) - The set of zero cells and BFS queue can store O(RC) cells.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
        {
            return -1;
        }

        // using bfs traversal to traverse here we can also traverse using dfs but it will take more time
        // so BFS

        set<pair<int,int>> st;

        zeros_location(grid, st);

        queue<pair<int,int>> q;

        q.push({0,0});

        st.erase({0,0});

        int path = 1;

        vector<pair<int,int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == row-1 && y == col-1)
                {
                    return path;
                }

                for(int i = 0; i < directions.size(); i++)
                {
                    int new_x = x + directions[i].first;
                    int new_y = y + directions[i].second;

                    // checking boundary and unvisited zero cell
                    if(new_x >= 0 && new_x < row &&
                       new_y >= 0 && new_y < col &&
                       st.find({new_x, new_y}) != st.end())
                    {
                        st.erase({new_x, new_y});

                        // if the neighbour is valid and unvisited
                        // pushing it into queue
                        q.push({new_x, new_y});
                    }
                }
            }
            // moving to next BFS level
            path++;
        }

        return -1;
    }

    void zeros_location(vector<vector<int>>& grid, set<pair<int,int>>& st)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    st.insert({i, j});
                }
            }
        }
    }
};

// Approach - 2
// Using Breadth-First Search with a Distance Matrix and a Set
// Time Complexity: O(RC log(RC)) - Each cell is processed once, and set operations take O(log(RC)).
// Space Complexity: O(RC) - The set, queue, and distance matrix require O(RC) auxiliary space.

class Solution1 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size() ;
        int col = grid[0].size() ;
        if(grid[0][0] == 1 || grid[row-1][col-1])
        {
            return -1;
        }
        // using bfs traversal to traverse here we can also traverse using dfs but it will take more time 
        // so BFS 
        
        set<pair<int,int>> st ;

        zeros_location(grid , st) ;

        queue<pair<int , int>> q ;
        
        q.push( {0,0} ) ;

        st.erase( {0 , 0} ) ;

        vector<vector<int>> distance(row, vector<int>(col, INT_MAX)); // this will store the path or destination 

        distance[0][0] = 1 ;

        while(!q.empty())
        {
            int x = q.front().first ;
            int y = q.front().second ;
            q.pop() ;

            vector< pair<int , int> > directions = {
                    {-1, -1}, {-1, 0}, {-1, 1},
                    { 0, -1},{ 0, 1}, { 1, -1},
                    { 1, 0}, { 1, 1}
                };
            
            for(int i = 0 ; i < directions.size() ; i++)
            {
                // now checking the adjacent cells 
                int new_x = x + directions[i].first ;
                int new_y = y + directions[i].second ;
                if( st.find( {new_x , new_y} ) != st.end()  )
                {
                    st.erase( {new_x , new_y} );
                    distance[new_x][new_y] = distance[x][y] + 1;

                    // if the neighbour is valid and unvisited this is checked by the st
                    // so pushing it into queue 
                    q.push( {new_x , new_y} );
                }
            }
        }
        return distance[row-1][col-1] == INT_MAX ? -1 : distance[row-1][col-1] ;
    }

    void zeros_location(vector<vector<int>>& grid , set<pair<int,int>> & st)
    {
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == 0)
                {
                    st.insert({i , j});
                }
            }
        }
    }
};