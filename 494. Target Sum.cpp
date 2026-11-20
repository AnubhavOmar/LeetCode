// Solution of LeetCode Problem
// 494. Target Sum
// Solution in CPP

// Approach - 1
// Using Recursion with Memoization
// Time Complexity: O(N * S) - Store results for up to N positions and possible sums from -S to S
// Space Complexity: O(N * S) - Memo table uses N by 2S+1 space, plus recursion stack

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return helper(0, 0, target, nums, dp, sum);
    }

    int helper(int i, int curr, int target, vector<int>& nums, vector<vector<int>>& dp, int offset)
    {
        // Base case
        if (i == nums.size()) {
            return curr == target ? 1 : 0;
        }

        // Memoization
        if (dp[i][curr + offset] != -1) {
            return dp[i][curr + offset];
        }

        // Add current element
        int add = helper(i + 1, curr + nums[i],
                         target, nums, dp, offset);

        // Subtract current element
        int subtract = helper(i + 1, curr - nums[i],
                              target, nums, dp, offset);

        return dp[i][curr + offset] = add + subtract;
    }
};


// Approach - 2
// Using Plain Recursion with Target Update
// Time Complexity: O(2^N) - Try adding and subtracting every number
// Space Complexity: O(N) - Recursive call stack can reach depth N

class Solution3 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0 , nums, target) ;
    }
    int helper(int i , vector<int>&nums , int target)
    {
        if(i >= nums.size())
        {
            if(target == 0)
            {
                return 1 ;
            }
            return 0 ;
        }

        return helper( i + 1  , nums , target + nums[i]) + 
            helper( i + 1  , nums , target - nums[i]);
    }
};


// Approach - 3
// Using Plain Recursion with Current Sum
// Time Complexity: O(2^N) - Try both signs for every number
// Space Complexity: O(N) - Recursive call stack can reach depth N

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return helper(0 , 0 , nums, target) ;
    }
    int helper(int curr , int i , vector<int>&nums , int target)
    {
        if(i >= nums.size())
        {
            if(curr == target)
            {
                return 1 ;
            }
            return 0 ;
        }

        return helper(curr + nums[i] , i + 1  , nums , target) + 
            helper(curr - nums[i] , i + 1  , nums , target);
    }
};


// Approach - 4
// Using Plain Recursion with a Reference Counter
// Time Complexity: O(2^N) - Explore both choices for each of the N numbers
// Space Complexity: O(N) - Recursive call stack can reach depth N

class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0 ; 
        helper( 0 , 0 , count , nums , target);
        return count;
    }
    void helper(int curr , int i , int & count , vector<int>&nums , int target)
    {
        if(i >= nums.size())
        {
            if(curr == target)
            {
                count++;
            }
            return ;
        }

        helper(curr + nums[i] , i + 1 , count , nums , target);

        helper(curr - nums[i] , i + 1 , count , nums , target);
    }
};