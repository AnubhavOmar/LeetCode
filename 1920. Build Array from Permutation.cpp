// Solution of LeetCode Problem 
// 1920. Build Array from Permutation
// Solution in CPP 

// Approach - 1 ( using brute force approach with O(n) space )

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans ;
        for(int i = 0 ; i<nums.size();i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans ;
    }
};

// Appraoch 2 