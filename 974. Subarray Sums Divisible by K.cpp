// Solution of LeetCode Problem 
// 974. Subarray Sums Divisible by K
// Solution in CPP 

// Approach - 1 (Brute Force) Time Complexity : O(n^2)

class Solution {
public:
// brute force approach 
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0 ; 
        for (int i =0 ;i<nums.size();i++)
        {
            int sum = 0 ;
            
            for(int j = i ; j<nums.size();j++)
            {
                sum = sum + nums[j] ;
                if(sum % k ==0 )
                {
                    count++ ;
                }
            }
        }
        return count ;
    }
};

// Approach - 2 (More Optimal Approach)  Time Complexity : O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for(int i = 1 ;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        vector<int>remainder ;
        remainder.push_back(0);
        for(int i = 0 ; i<n;i++)
        {
            int r = prefix_sum[i] % k;
            if (r < 0) r += k;
            remainder.push_back(r);
        }
        map<int , int > mp ;
        for(int i = 0 ; i<n+1;i++)
        {
            mp[remainder[i]]++;
        }
        int ans = 0 ;
        for(auto a : mp)
        {
            ans += (a.second * (a.second - 1))/2;
        }
        return ans; 
    }
};