// Solution of LeetCode Problem 
// 53. Maximum Subarray
//  Solution in CPP 


// Approach - 1 (Brute Force)
// Time Complexity: O(n^3)
// Space Complexity: O(1)


class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int sum = 0;

                for (int k = i; k <= j; k++) {

                    sum += nums[k];
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};



// Approach - 2 (Better Approach)
// Time Complexity: O(n^2)
// Space Complexity: O(1)


class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};



// Approach - 3 (Kadane's Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)
 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++) {

            // Agar previous subarray ka sum negative ho gaya hai,
            // to us negative sum ko aage carry karne ka koi fayda nahi hai.
            // Isliye us subarray ko yahi drop kar dete hain aur
            // current element se naya subarray start karte hain.
            if (sum < 0) {
                sum = 0;
            }

            // Current element ko current subarray me include karo.
            sum += nums[i];

            // Har iteration me answer update karte raho.
            ans = max(ans, sum);
        }

        return ans;
    }
}