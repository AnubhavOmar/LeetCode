// Solution of LeetCode Problem 
// 2644. Find the Maximum Divisibility Score 

// Approach - 1 

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = -1 ;                
        int minn = INT_MAX;                 
        for(int i = 0 ; i < divisors.size(); i++)
        {
            int count = 0;
            
            for(int j = 0 ; j < nums.size(); j++)
            {
                if(nums[j] % divisors[i] == 0)
                {
                    count++;
                }
            }

            if(count > ans)
            {
                ans = count;
                minn = divisors[i];
            }
            else if(count == ans && divisors[i] < minn)
            {
                minn = divisors[i];
            }
        }

        return minn;
    }
};
