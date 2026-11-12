// Solution of LeetCode Problem
// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// Solution in CPP

// Approach - 1
// Using Two Directional Monotonic Scans
// Time Complexity: O(n) - Scan the array once for increasing subarrays and once for decreasing subarrays.
// Space Complexity: O(1) - Uses only a constant amount of auxiliary space.

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() ;
        if( n == 1 ) return 1 ;
        int count1 = increasing(nums) ;
        int count2 = decreasing(nums) ;
        return max(count1 , count2 );
    }
    int increasing(vector<int>&nums)
    {
        int ans = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int curr_count = 1 ;
            for(int j = i + 1 ; j < n ; j++)
            {
                if(nums[i] >= nums[j])
                {
                    break;
                }
                curr_count++;
                i++;
            }
            ans = max(ans , curr_count);
        }
        return ans;
    }
    int decreasing(vector<int>&nums)
    {
        int ans = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int curr_count = 1 ;
            for(int j = i + 1 ; j < n ; j++)
            {
                if(nums[i] <= nums[j])
                {
                    break;
                }
                curr_count++;
                i++;
            }
            ans = max(ans , curr_count);
        }
        return ans;
    }
};