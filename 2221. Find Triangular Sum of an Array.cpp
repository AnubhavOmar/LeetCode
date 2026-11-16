// Solution of LeetCode Problem
// 2221. Find Triangular Sum of an Array
// Solution in CPP

// Approach - 1
// Using In-Place Simulation
// Time Complexity: O(N^2) - Process the array for N-1 rounds, with a shorter pass each round
// Space Complexity: O(1) - Reuse the input array and use constant extra space

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size() ; 

        while(n > 1) 
        {
            for(int i = 0 ; i < n - 1 ; i++)
            {
                nums[i] = (nums[i] + nums[i+1]) % 10 ;
            }
            n--;
        }
        return nums[0] ;
    }
};


// Approach - 2
// Using Simulation with a Temporary Vector
// Time Complexity: O(N^2) - Process all remaining elements over N-1 rounds
// Space Complexity: O(N) - Create a temporary vector for the next row

class Solution1 {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1) 
        {
            vector<int>vec(nums.size() - 1);
            for(int i = 0 ; i < nums.size() - 1 ; i++)
            {
                vec[i] = (nums[i] + nums[i+1]) % 10 ;
            }
            nums.clear() ;
            nums = vec ;
        }
        return nums[0] ;
    }
};