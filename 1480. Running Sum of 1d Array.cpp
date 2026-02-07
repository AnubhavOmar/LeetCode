// Solution of LeetCode 
// 1480. Running Sum of 1d Array 
// Solution in CPP 

// Appraoch - 1   (Using an extra vector)


// Time Complexity = O(n);
// Space Complexity = O(n); 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n);
        ans[0] = nums[0];
        for(int i = 1 ; i<nums.size() ;i++)
        {
            ans[i] = ans[i-1] + nums[i];
        }
        return ans ;
    }
};


// Appraoch - 2   (Without Using an extra vector)


// Time Complexity = O(n);
// Space Complexity = O(1); 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for(int i = 1 ; i<nums.size() ;i++)
        {
            nums[i] = nums[i-1] + nums[i];
        }
        return nums ;
    }
};