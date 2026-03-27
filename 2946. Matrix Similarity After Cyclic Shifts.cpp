// Solution of LeetCode POTD 
// 2946. Matrix Similarity After Cyclic Shifts
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        k = k % mat[0].size();
        
        vector<vector<int>> mat2 = mat;

        for(int i = 0; i < mat.size(); i++)
        {
            if(i % 2 == 0)
            {
                for(int t = 0; t < k; t++)
                    mat2[i] = left(mat2[i]);
            }
            else 
            {
                for(int t = 0; t < k; t++)
                    mat2[i] = right(mat2[i]);
            }
        }
        
        return mat2 == mat;
    }

    vector<int> left(vector<int> arr)
    {
        int first = arr[0];
        for(int i = 0; i < arr.size() - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[arr.size() - 1] = first;
        return arr;
    }

    vector<int> right(vector<int> arr)
    {
        int last = arr[arr.size() - 1];
        for(int i = arr.size() - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
        return arr;
    }
};
