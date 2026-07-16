// Solution of LeetCode POTD 
// 3867. Sum of GCD of Formed Pairs
// Solution in CPP

// Approach - 1 
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ;
        int maxx = nums[0] ;
        vector<int>prefix_sum ;

        for(int i = 0 ; i<n ; i++)
        {
            maxx = max(maxx,nums[i]);
            prefix_sum.push_back(gcd(maxx , nums[i]));
        }
        
        sort(prefix_sum.begin(),prefix_sum.end());

        long long sum = 0 ;
        int i = 0 ; 
        int j = prefix_sum.size() - 1 ;
        while(i < j )
        {
            sum += gcd(prefix_sum[i] ,prefix_sum[j] );
            i++;
            j--;
        }
        return sum ;
    }
};