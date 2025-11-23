// Solution of LeetCode Problem 
// 1262. Greatest Sum Divisible by Three 

// Approach - 1 

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end()); 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 3 == 0) return sum;

        int best = 0;

        for (int i = 0; i < n; i++) {
            if ((sum - nums[i]) % 3 == 0) {
                best = max(best, sum - nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((sum - nums[i] - nums[j]) % 3 == 0) {
                    best = max(best, sum - nums[i] - nums[j]);
                }
            }
        }

        return best;
    }
};


