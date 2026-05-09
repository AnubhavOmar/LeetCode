// Solution of LeetCode POTD
// 1914. Cyclically Rotating a Grid
// Solution in CPP

// Approach- 1

// Logic -->  main logic is that har layer ke elements ko nikal rhe hai phle top row then right column then bottom row then left column then ussko temp me store kar rhe hai then uss temp ko jitni baar rotate karna hai ussko rotate karenge then rotated array hame uss layer ke correct position of their elements de rhi hogi then uss rotated array ko wapas se gird me insert kara de rhe hai jiss order me elements ko extract kiya tha 

// aur ye work har layer ke leye kar rhe hai 

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        int layers = min(m,n) / 2 ;

        for(int i = 0 ; i < layers ; i++)
        {

            vector<int> temp = extract_layer_elements(grid , i); 
            //  this will store the elements which are extracted from the layer 

            vector<int> rotated_array = rotates_array(temp , k);
            // this holds the elements in their correct position where they should have to be in grid after kth rotation 

            insert_rotated_elements(grid , rotated_array , i);
            // this funtion will insert the clockwise rotated elements in their position in whcih they are extracted 

        }

        return grid ;
    }


private : 
    vector<int> extract_layer_elements(vector<vector<int>>& grid, int layer )
    {
        vector<int>temp ; 
        int m = grid.size() ;
        int n = grid[0].size() ;

        // top row
        for(int j = layer; j <= n - layer - 1; j++)
        {
            temp.push_back(grid[layer][j]);
        }

        // right column
        for(int i = layer + 1; i <= m - layer - 1; i++)
        {
            temp.push_back(grid[i][n - layer - 1]);
        }

        // bottom row
        for(int j = n - layer - 2; j >= layer; j--)
        {
            temp.push_back(grid[m - layer - 1][j]);
        }

        // left column
        for(int i = m - layer - 2; i > layer; i--)
        {
            temp.push_back(grid[i][layer]);
        }
        return temp ;
    }

    vector<int> rotates_array(vector<int>& temp, int k )
    {
       int n = temp.size();
        k = k % n;
        vector<int> rotated;

        // first push from k -> end
        for(int i = k; i < n; i++)
        {
            rotated.push_back(temp[i]);
        }

        // then push from 0 -> k-1
        for(int i = 0; i < k; i++)
        {
            rotated.push_back(temp[i]);
        }
        return rotated;
    }

    void insert_rotated_elements(vector<vector<int>>& grid,vector<int>& rotated,int layer)
    {
        int m = grid.size();
        int n = grid[0].size();

        int idx = 0;

        // top row
        for(int j = layer; j <= n - layer - 1; j++)
        {
            grid[layer][j] = rotated[idx++];
        }

        // right column
        for(int i = layer + 1; i <= m - layer - 1; i++)
        {
            grid[i][n - layer - 1] = rotated[idx++];
        }

        // bottom row
        for(int j = n - layer - 2; j >= layer; j--)
        {
            grid[m - layer - 1][j] = rotated[idx++];
        }

        // left column
        for(int i = m - layer - 2; i > layer; i--)
        {
            grid[i][layer] = rotated[idx++];
        }
    }

};
