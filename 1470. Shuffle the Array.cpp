// Solution of LeetCode Problem  
//  1470. Shuffle the Array

// Approach - 1 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vec1 ; 
        for(int i = 0 ; i<n;i++)
        {
            vec1.push_back(nums[i]);
        }
        vector<int> vec2 ; 
         for(int i = n ; i<2*n;i++)
        {
            vec2.push_back(nums[i]);
        }
        nums.clear() ; 
        for(int i = 0 ;i<n ;i++)
        {
            nums.push_back(vec1[i]);
            nums.push_back(vec2[i]);
        }
        return nums;
    }
};

// Appraoch - 2 without vector 1 and vector 2 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans ; 
        int j =n ; 
        for(int i = 0 ; i<n ;i++,j++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    
    }
};


