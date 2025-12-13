// Solution of LeetCode Problem 
// 209. Minimum Size Subarray Sum 
// Solution in CPP 

// Appraoch - 1 (Brute Force) 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n  = nums.size() ; 
        int minlen = INT_MAX;
        for(int i = 0 ; i<n;i++)
        {
            int currsum = 0 ; 
            for(int j = i ; j<n;j++)
            {
                currsum += nums[j];
                if(currsum >= target)
                {
                    minlen = min(minlen,j-i+1);
                    break ;
                }
            }
        }
        return (minlen == INT_MAX) ? 0 :minlen;
    }
};

// Appraoch - 2  (Optimal Approach) 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int i = 0 ; 
        int  j =0; 
        int minlen = INT_MAX;
        int sum = 0 ; 
        while(j<n)
        {
            sum += nums[j];
            while(sum>=target)
            {
            minlen = min(minlen,j-i+1);
            sum -= nums[i];
            i++;
            }
            j++;
        }
        return (minlen==INT_MAX) ? 0 :minlen ;
    }
};
