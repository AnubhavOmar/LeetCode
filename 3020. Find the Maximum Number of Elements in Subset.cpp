// Solution of LeetCode POTD
// 3020. Find the Maximum Number of Elements in Subset
// Solution in CPP 

// Approach - 1 (Using HashMap)

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long>ump;
        for(int i = 0 ; i<nums.size();i++)
        {
            ump[nums[i]]++;
        }
        int ans = 0 ; 

        for(int i = 0 ; i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                int cnt = ump[1] ;
                if(cnt % 2 == 0)
                {
                    ans = max(cnt-1, ans) ;
                }
                else 
                {
                    ans = max(cnt, ans) ;
                }
                continue;
            }
            long long current = nums[i];
            int every_count = 0;
            while( ump[current] >=2 )
            {
                every_count+=2;
                current = current * current ;
            }
            if(ump[current] >= 1)
            {
                every_count++;
            }
            else
            {
               every_count--; 
            }
            ans = max(every_count, ans);
        }
        return ans;
    }
};