// Solution of LeetCode POTD
// 3876. Construct Uniform Parity Array II
// Solution in CPP 

// Approach - 1
// Using Minimum Even and Odd Parity Check
// Time Complexity: O(N) - Linear scan of the array of size N to find minimum even and odd elements
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_even = INT_MAX - 1  ;
        int min_odd = INT_MAX ;

        int n = nums1.size() ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums1[i] % 2 == 0)
            {
                min_even = min(min_even , nums1[i]) ;
            }
            else 
            {
                min_odd = min(min_odd , nums1[i]) ;
            }
        }
        
        if(min_odd == INT_MAX )
        {
            return true ; 
        }
        else if(min_even == INT_MAX - 1)
        {
            return true ;
        }
        return min_even >= min_odd ;
    }
};