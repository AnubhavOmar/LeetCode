// Solution of LeetCode Problem
// 3364. Minimum Positive Sum Subarray
// Solution in CPP

// Approach - 1
// Using Brute Force Subarray Enumeration
// Time Complexity: O((R - L + 1) * N^3) - For each size, checks all windows and calculates each sum by scanning its elements
// Space Complexity: O(1) - Uses only constant extra variables

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int sum = INT_MAX ;

        for(int i = l ; i <= r ; i++)
        {
            int help = subarray(nums , i);
            if(help > 0)
            {
                sum = min(sum , help) ;
            }
        }
        return sum == INT_MAX ? -1 : sum ;
    }
    int subarray(vector<int>&nums , int sizee)
    {
        if( sizee > nums.size() ) return -1;

        int sum = INT_MAX ;

        for(int i = 0 ; i <= nums.size() - sizee ; i++)
        {
            for(int j = i ; j < nums.size() ; j++)
            {
                if( j - i + 1  > sizee)
                {
                    break;
                } 
                if( j - i + 1 != sizee)
                {
                    continue ;
                }
                int summ = 0 ;
                for(int k = i ; k <= j ; k++)
                {
                    summ += nums[k];
                }
                if(summ > 0)
                {
                    sum = min(sum , summ);
                }
            }
        }
        return sum == INT_MAX ? -1 : sum ;
    }
};