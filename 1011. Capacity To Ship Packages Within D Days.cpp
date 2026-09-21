// Solution of LeetCode Problem
// 1011. Capacity To Ship Packages Within D Days
// Solution in CPP

// Approach - 1
// Using Binary Search on Capacity
// Time Complexity: O(N * log(SUM_WEIGHTS - MAX_WEIGHT)) - Binary search over the capacity range, checking each capacity in O(N)
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        int maxx = INT_MIN ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            maxx = max(maxx , weights[i]) ;
            sum += weights[i] ;
        }
        int low = maxx ;
        int high = sum ;
        int ans ;
        while(low <= high)
        {
            int mid = (low + high) / 2 ;
            if(helper(weights , days , mid))
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else
            {
                low = mid + 1 ;
            }
        }
        return ans;
    }
    bool helper(vector<int> & weights , int days , int curr_ship_weight)
    {
        int n = weights.size() ;
        int curr_weight_sum = 0 ;
        int req_days = 1 ;
        for(int i = 0 ; i < n ; i++)
        {
            if (curr_weight_sum + weights[i] > curr_ship_weight)
            {
                req_days++;
                curr_weight_sum = 0;
            }

            curr_weight_sum += weights[i];
        }
        return req_days <= days ;
    }
};


// Approach - 2
// Using Brute Force Linear Search Over Capacity
// Time Complexity: O(N * (SUM_WEIGHTS - MAX_WEIGHT)) - Linear search through the capacity range, checking each in O(N)
// Space Complexity: O(1) - Constant auxiliary space used

// Approach - 2 Using Brute Force 

class Solution1 {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        int maxx = INT_MIN ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            maxx = max(maxx , weights[i]) ;
            sum += weights[i] ;
        }
        for(int i = maxx ; i <= sum ; i++)
        {
            if(helper(weights , days , i))
            {
                return i ;
            }
        }
        return sum ;
    }
    bool helper(vector<int> & weights , int days , int curr_ship_weight)
    {
        int n = weights.size() ;
        int curr_weight_sum = 0 ;
        int req_days = 1 ;
        for(int i = 0 ; i < n ; i++)
        {
            if (curr_weight_sum + weights[i] > curr_ship_weight)
            {
                req_days++;
                curr_weight_sum = 0;
            }

            curr_weight_sum += weights[i];
        }
        return req_days <= days ;
    }
};