// Solution of the LeetCode Problem 
// 713. Subarray Product Less Than K
// Solution in CPP 

// Approach - 1 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // If k <= 1, no positive product can be < k
        if (k <= 1) return 0;

        int n = nums.size();
        int count = 0;

        int start = 0;          // Left pointer for sliding window
        int end = 0;            // Right pointer for sliding window
        int product = 1;        // Stores product of current window

        // Expand the window using 'end'
        while (end < n) {

            product *= nums[end];       // Multiply current element to window product

            // If product becomes >= k, shrink window from the left
            while (product >= k) {
                product /= nums[start];
                start++;
            }

            // Add number of valid subarrays ending at 'end'
            // Example: window size = (end-start+1) gives all subarrays ending at 'end'
            count += (end - start + 1);

            end++;  // expand window
        }

        return count;
    }
};
