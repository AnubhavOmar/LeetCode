// Solution of LeetCode POTD
// 3875. Construct Uniform Parity Array I
// Solution in CPP

// Approach - 1
// Using Parity Check and Transformation
// Time Complexity: O(N) - Linear scan of the array of size N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size() ;

        if( n == 1 ) return true ;

        int parity = true; 
        int idx = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums1[i] % 2 != 0)
            {
                idx = i ;
                parity = false;
                break ;
            }
        }

        if(!parity)
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(i != idx && nums1[i] % 2 == 0)
                {
                    nums1[i] = nums1[i] - nums1[idx] ;
                }
            }
            parity = true ;
        }

        return parity ;
    }
};