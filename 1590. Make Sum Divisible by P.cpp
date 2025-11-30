// Solution of LeetCode problem 
// 1590. Make Sum Divisible by P
// Solution in CPP 


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0 ; 
        int req = 0 ; 
        for(int   i = 0 ; i<nums.size() ; i++)
        {
            sum += nums[i];
        }
        req = sum % p ;
        if (sum<p) return -1 ;
        if(req == 0) return 0 ;
        long long prefix = 0 ;
        unordered_map<int,int>m;
        m[0]=-1 ;
        int ans = nums.size() ;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            prefix = (prefix + nums[i]) % p ;
            int target = (prefix - req + p) % p ;
            if(m.find(target) != m.end())
            {
                ans = min (ans, i - m[target]);
            }
            m[prefix]= i ;
        }
        return (ans == nums.size()) ? -1 : ans  ;
        }
};