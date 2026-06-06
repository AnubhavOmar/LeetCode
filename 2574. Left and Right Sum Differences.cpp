// Solution of LeetCode POTD
// 2574. Left and Right Sum Differences
// Solution in CPP

// Approach - 1 (Using Prefix Sum)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size() ;

        // Calculating Prefix Sum
        vector<int>prefix_sum(n);
        prefix_sum[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i] ;
        }

        // Calculating Right Sum
        vector<int>right_sum;
        for(int i = 0 ; i < n ; i++)
        {
            right_sum.push_back(abs(prefix_sum[i] - prefix_sum[n-1]));
        }
        
        // Calculating Left Sum
        vector<int>left_sum(n);
        left_sum[0] = 0 ; 
        for(int i = 1 ; i< n ; i++)
        {
            left_sum [i] = prefix_sum[i-1] ;
        }
        
        // Calculating answer[i] = abs(leftSum[i] - rightSum[i])
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++)
        {
            ans.push_back(abs(left_sum[i] - right_sum[i])) ;
        }
        return ans;
        
    }
};