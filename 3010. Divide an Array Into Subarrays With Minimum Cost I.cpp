// Solution of LeetCode Problem 
// 3010. Divide an Array Into Subarrays With Minimum Cost I 
// Solution in CPP

// Approach - 1 (Using Sorting)

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() + 1, nums.end());
        return (nums[0]+nums[1]+nums[2]); 
    }
};

// Appraoch - 2 (Using without sorting more optimal) 

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first_min = INT_MAX;
        int second_min = INT_MAX;
        for(int i = 1 ; i<nums.size();i++)
        {
            if(first_min > nums[i])
            {
                second_min = first_min;
                first_min = nums[i];
            }
            else if(second_min > nums[i])
            {
                second_min = nums[i];
            }
        }
        return (nums[0] + first_min + second_min);
    }
};