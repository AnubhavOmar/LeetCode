// Solution of Leetcode Problem 
// 74. Search a 2D Matrix

// Approach - 1 (Brute Force)

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    // brute force 
    for(int i = 0 ; i <matrixSize;i++)
        {
            for(int j= 0 ;j<*matrixColSize;j++)
            {
                if(matrix[i][j]==target){
                    return true ;
                }
            }
        }
        return false ;
    }