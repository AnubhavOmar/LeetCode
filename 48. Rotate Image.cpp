// Solution of LeetCode POTD
// 48. Rotate Image
// Solution in CPP

// Approach - 1  (Doing Transpose of the Matrix And then reversing all the rows for 90 degree rotation) 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0 ; i<matrix.size() ; i++)
        {
            for(int j = i + 1 ; j < matrix[i].size() ; j++ )
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ; i<matrix.size() ; i++)
        {
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};
