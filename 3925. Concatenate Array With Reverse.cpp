// Solution of LeetCode Problem 
// 3925. Concatenate Array With Reverse
// Solution in CPP

// Approach - 1 

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size() ;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};