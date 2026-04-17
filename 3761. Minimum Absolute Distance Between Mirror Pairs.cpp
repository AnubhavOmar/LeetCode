// Solution of LeetCode POTD
// 3761. Minimum Absolute Distance Between Mirror Pairs
// Solution in CPP 

// Approach - 1

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        unordered_map<string,int>mp;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            mp[to_string(nums[i])] = i ;
        }
        int ans = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            while(nums[i] % 10 == 0)
            {
                nums[i] /= 10 ;
            }
            string s = to_string(nums[i]);
            reverse(s.begin(),s.end());
            if( (mp.find(s) != mp.end()) && (mp[s] > i))
            {
                ans = min(ans , abs(i - mp[s]));
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};