// Solution of LeetCode Problem
// 198. House Robber
// Solution in CPP

// Approach - 1
// Using Dynamic Programming with Rolling State
// Time Complexity: O(n) - Each house is processed once.
// Space Complexity: O(1) - Only two previous states are stored.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        int prev1 = 0 ; 
        int prev2 = 0 ;

        for(int i = 0 ; i< n ; i++)
        {
            int current = max(prev1 , prev2 + nums[i]) ;
        
            prev2 = prev1 ;
            prev1 = current ;
        } 
        return prev1 ;
    }
};

// Approach - 2
// Using Top-Down Dynamic Programming
// Time Complexity: O(n) - Each index is solved once and memoized.
// Space Complexity: O(n) - The DP array plus recursion stack are used.

class Solution4 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, n - 1, dp);
    }

    int solve(vector<int>& nums, int i, vector<int>& dp) {
        // Base cases
        if (i == 0)
            return nums[0];

        if (i < 0)
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // Choice 1: Rob current house
        int pick = nums[i] + solve(nums, i - 2, dp);

        // Choice 2: Skip current house
        int notPick = solve(nums, i - 1, dp);

        // Store and return the best answer
        return dp[i] = max(pick, notPick);
    }
};

// Approach - 3
// Using Exhaustive Subset Generation
// Time Complexity: O(2^n) - All subsets are enumerated.
// Space Complexity: O(2^n) - The generated subset list can be exponential.

class Solution3 {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> all_subset_index;
        vector<int> partial;

        subset(nums, all_subset_index, 0, partial);

        int ans = 0;

        for (int i = 0; i < all_subset_index.size(); i++)
        {
            ans = max(ans, cal_sum(nums, all_subset_index[i]));
        }

        return ans;
    }

    void subset(vector<int>& nums,vector<vector<int>>& all_subsets,int i,vector<int>& partial_set)
    {
        // Base case
        if (i == nums.size())
        {
            all_subsets.push_back(partial_set);
            return;
        }

        // Choice 1: Select current index only if valid
        if (partial_set.empty() || partial_set.back() != i - 1)
        {
            partial_set.push_back(i);

            subset(nums, all_subsets, i + 1, partial_set);

            // Backtrack
            partial_set.pop_back();
        }

        // Choice 2: Skip current index
        subset(nums, all_subsets, i + 1, partial_set);
    }

    int cal_sum(vector<int>& nums, vector<int>& vec)
    {
        int sum = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            sum += nums[vec[i]];
        }

        return sum;
    }
};

// Approach - 4
// Using Exhaustive Subset Generation with Validity Check
// Time Complexity: O(2^n) - All subsets are generated and checked.
// Space Complexity: O(2^n) - The subset list and temporary vectors are exponential.

class Solution2 {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>>all_subset_index  ;
        vector<int> partial ;
        subset(nums , all_subset_index , 0 , partial );

        int ans = 0 ;

        for(int i = 0 ; i < all_subset_index.size() ; i++)
        {
            if(is_valid(all_subset_index[i]))
            {
                ans = max(ans , cal_sum( nums , all_subset_index[i]));
            }
        }
        return ans;
    }
    bool is_valid(vector<int> vec)
    {
        for(int i = 1 ; i < vec.size() ; i++)
        {
            if(vec[i] - vec[i-1] == 1) return false  ;
        }
        return true  ;
    }
    void subset(vector<int>& nums, vector<vector<int>>& all_subsets, int i, vector<int>& partial_set)
    {
        // Base case
        if (i == nums.size())
        {
            all_subsets.push_back(partial_set);
            return;
        }

        // step_1: Select current index
        partial_set.push_back(i);
        subset(nums, all_subsets, i + 1, partial_set);

        // Backtrack: Undo selection
        partial_set.pop_back();

        // step_2: Skip current index
        subset(nums, all_subsets, i + 1, partial_set);
    }

    int cal_sum(vector<int>& nums, vector<int>& vec)
    {
        int sum = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            sum += nums[vec[i]];
        }

        return sum;
    }

};

// Approach - 5
// Using Recursive Exhaustive Search
// Time Complexity: O(2^n) - Every branch explores the choice to rob or skip a house.
// Space Complexity: O(n) - Recursive depth is up to n.

class Solution1 {
public:
    int rob(vector<int>& nums) {
        int maxVal = 0;
        int i = 0;
        int subsetValue = 0;

        traverse(i, subsetValue, nums.size(), maxVal, nums);

        return maxVal;
    }

private:
    void traverse(int i, int subsetValue, int n,
                  int& maxVal, vector<int>& nums) {
        if (i >= n) {
            maxVal = max(subsetValue, maxVal);
            return;
        }

        // Without robbing the current house
        traverse(i + 1, subsetValue, n, maxVal, nums);

        // Rob the current house and skip the adjacent house
        traverse(i + 2, subsetValue + nums[i], n, maxVal, nums);
    }
};