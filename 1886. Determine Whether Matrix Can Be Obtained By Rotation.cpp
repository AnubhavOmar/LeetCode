// Solution of LeetCode POTD 
// 1886. Determine Whether Matrix Can Be Obtained By Rotation
// Solution in CPP

// Approach - 1  (Evrytime Rotating Matrix and then checking it with target )

class Solution {
public:

    vector<vector<int>> rotated_vector(vector<vector<int>>& mat)
{
    int n = mat.size() ;

    vector<vector<int>> rotated(n, vector<int>(n));
    
    
    for(int i = 0 ; i<mat.size() ; i++ )
    {
        for(int j = 0 ; j<mat.size() ; j++)
        {
            rotated[ j ][ n - i - 1 ] = mat[i][j];
        }
    }
    return rotated ;
}



    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        
        for(int i = 0 ; i<4 ; i++)
        {
            if(mat == target )
            {
                return true;
            }
            mat = rotated_vector(mat);
        }
        return false ;
    }
};