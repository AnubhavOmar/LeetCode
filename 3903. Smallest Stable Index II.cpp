// Solution of LeetCode Problem
// 3903. Smallest Stable Index II
// Solution in CPP

// Approach - 1
// Using Optimized Suffix Min Array and Running Maximum
// Time Complexity: O(N) - Linear passes over the array of size N
// Space Complexity: O(N) - Storing suffix minimum values in an auxiliary vector

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;

        vector<int>minn( n , INT_MAX) ;

        int maxx = nums[0] ;
        minn[n-1] = nums[n-1] ;

    

        for(int i = n - 2 ; i >= 0 ; i--)
        {
            minn[i] = min(minn[i+1] , nums[i]) ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            maxx = max(maxx , nums[i]) ;

            if( ( maxx-  minn[i]) <= k )
            {
                return i ;
            }
        }
        return -1 ;
    }
};

// Approach - 2
// Using Prefix Max and Suffix Min Arrays
// Time Complexity: O(N) - Linear passes over the array of size N to compute prefix maximums, suffix minimums, and check condition
// Space Complexity: O(N) - Storing prefix maximums and suffix minimums in auxiliary vectors

class Solution1 {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int>maxx( n , INT_MIN) ;
        vector<int>minn( n , INT_MAX) ;

        maxx[0] = nums[0] ;
        minn[n-1] = nums[n-1] ;

        for(int i = 1 ; i < n ; i++)
        {
            maxx[i] = max(maxx[i-1] , nums[i]) ;
        }

        for(int i = n - 2 ; i >= 0 ; i--)
        {
            minn[i] = min(minn[i+1] , nums[i]) ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            if( ( maxx[i] -  minn[i]) <= k )
            {
                return i ;
            }
        }
        return -1 ;
    }
};