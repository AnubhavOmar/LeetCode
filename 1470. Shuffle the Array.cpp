// Solution of LeetCode Problem  
//  1470. Shuffle the Array
// Solution in CPP

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