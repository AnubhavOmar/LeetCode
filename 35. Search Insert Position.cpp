// // Sollution of LeetCode problem 
// 35. Search Insert Position
// Solution in CPP

// Approach 1: Manual Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1;
        int ans = n  ;
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            if( nums[mid] >= target)
            {
                ans = mid ;
                high = mid - 1;
            } 
            else 
            {
                low = mid + 1 ;
            }
        }
        return ans;
    }
};

// Approach 2: Using STL lower_bound
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();        
    }
};