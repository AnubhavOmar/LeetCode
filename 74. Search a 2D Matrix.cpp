// Solution of Leetcode Problem 
// 74. Search a 2D Matrix
// Solution in CPP 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time Complexity : O(log n + log n) 

        // applying two binary searches first two search the row then second binary search to find in the target on that row only 
        
        int start = 0 ; 
        int end = matrix.size() - 1 ;

        int row_size = matrix[0].size();   
        int row_target_exit = -1 ;         
        
        while(start <= end )
        {
            int mid = start + (end - start) / 2;

            // direct match
            if(matrix[mid][0] == target || matrix[mid][row_size - 1] == target) 
                return true;

            else if(matrix[mid][0] <= target && matrix[mid][row_size - 1] >= target)
            {
                row_target_exit = mid;
                break;  
            }
            else if(target < matrix[mid][0])
            {
                end = mid - 1;   
            }
            else
            {
                start = mid + 1; 
            }
        }

        // if no valid row found
        if(row_target_exit == -1) return false;

        // second binary search
        int s = 0;
        int e = row_size - 1;

        while(s <= e)
        {
            int mid = s + (e - s) / 2;

            if(matrix[row_target_exit][mid] == target) return true;
            else if(matrix[row_target_exit][mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
    }
};


class Solution3 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // applying for loop to find that in which the target can exits 

        int row  = 0 ; 
         
        for(int i = 0 ; i<matrix.size() ; i++)
        {
            if(matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target)
            {
                row = i ;
            }
        }

        // applying binary search to find the target in that row 

        int st = 0 ;
        int end = matrix[row].size() - 1 ;
        while( st <= end)
        {
            int mid = ( st + end ) / 2 ;
            if(matrix[row][mid] == target) return true; 
            else if( matrix[row][mid] < target ) st = mid + 1;
            else end = mid - 1 ;
        }
        return false ;
    }
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // flatnning the grid 
        vector<int>vecc ;
        for(int i = 0 ; i<matrix.size() ; i++)
        {
            for(int j = 0 ; j<matrix[i].size() ; j++)
            {
                vecc.push_back(matrix[i][j]);
            }
        }

        // now applying binary search 

        int st = 0 ;  
        int end = vecc.size() - 1 ; 
        while(st<=end)
        {
            int mid = ( st + end ) / 2 ;
            if( vecc[mid] == target ) return true ;
            else if( vecc[mid] > target) end = mid - 1 ;
            else st = mid + 1 ;
        }
        return false ;
    }
};



class Solution1 {
public:
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
};
