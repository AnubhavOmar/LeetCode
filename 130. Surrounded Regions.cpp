// Solution of LeetCode Problem
// 130. Surrounded Regions
// Solution in CPP

// Approach - 1
// Using Boundary-Based DFS with In-Place Marking
// Time Complexity: O(mn) - Each cell is scanned and each reachable boundary-connected cell is visited once.
// Space Complexity: O(mn) - The recursion stack can reach O(mn) in the worst case.

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();

        if (m == 0) return;

        int n = board[0].size();

        // Step 1: Find boundary-connected O and mark them as '#'
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == 'O') 
                {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) 
                    {
                        find_connected(i, j, board);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void find_connected(int i, int j,vector<vector<char>>& board)
    {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            return;
        }

        if (board[i][j] == 'X' || board[i][j] == '#') 
        {
            return;
        }

        // Mark the current O as boundary-connected
        board[i][j] = '#';

        find_connected(i + 1, j, board);
        find_connected(i - 1, j, board);
        find_connected(i, j + 1, board);
        find_connected(i, j - 1, board);
    }
};

// Approach - 2
// Using Boundary-Based DFS with an Ordered Set
// Time Complexity: O(mn log(mn)) - Each cell can be inserted or searched in the set with O(log(mn)) cost.
// Space Complexity: O(mn) - The set and recursion stack can each require O(mn) space.

class Solution1 {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size() ;
        int n = board[0].size() ;

        set<pair<int,int>> edge_connected ;

        // first we will traverse in the grid and find all the points which are connected to the edge or those are edge so we push them in edge_connected and then converting all 'O' to 'X' which are not in edge_connected ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 'O' && edge_connected.find({i , j}) == edge_connected.end())
                {
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        // it is an edge
                        find_connected(i , j , board , edge_connected) ;
                    }
                }
            }
        }
        
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 'O' && edge_connected.find({i, j}) == edge_connected.end())
                {
                    board[i][j] = 'X';
                }
            }
        }

        
    }

    void find_connected(int i , int j , vector<vector<char>>& board ,         set<pair<int,int>> & edge_connected )
    {
        if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            // out of board 
            return ;
        }
        if(board[i][j] == 'X' || edge_connected.find( {i , j } ) != edge_connected.end() )
        {
            // already present
            return ;
        }

        edge_connected.insert( { i , j } ) ;
        
        find_connected(i + 1 , j , board , edge_connected) ;
        find_connected(i - 1 , j , board , edge_connected) ;
        find_connected(i , j + 1 , board , edge_connected) ;
        find_connected(i , j - 1, board , edge_connected) ;
        
    }
};