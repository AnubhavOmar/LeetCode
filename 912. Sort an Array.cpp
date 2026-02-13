// Solution of Leetcode Problem 
// 912. Sort an Array
// Solution in cpp 

// Approach - 1 (Using recursion) 
// Time Complexity: O(n log n)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        sortArray(nums,0,nums.size()-1);
        return nums ;
    }
private : 
    void sortArray(vector<int> & nums , int i , int j)
    {
        // base case 
        if(j-i+1 <=1) return ;


        // 1. subproblems 

        int m = (i+j) / 2 ;
        sortArray(nums , i ,m);
        sortArray(nums , m+1 , j);
        
        // 2. Extension  // or merging of the array 
        vector<int> buf ;
        int i2 = i , j2 = m+1 ;
        while( (i2<=m || j2<=j) )
        {
            if( j2 > j || ( i2<=m  && nums[i2]<=nums[j2] ))
            {
                buf.push_back(nums[i2]);
                i2++;
            }
            else 
            {
                buf.push_back(nums[j2]);
                j2++;
            }
        }
        for(int k = 0 ; k<buf.size() ; k++)
        {
            nums[i+k] = buf[k];
        }
    }
};


// Approach 2: Using built-in sort() (for comparison only, not used as main solution)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return nums;
    }
};