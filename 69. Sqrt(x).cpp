// Solution of LeetCode Problem 
// 69. Sqrt(x)
// Solution in CPP
 
// Approach - 1
// Using Built-in Function
// Time Complexity: O(1) - Assuming constant time for optimized library sqrt implementation
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    int mySqrt(int x) {
      return int (sqrt(x));  
    }
};

// Approach - 2
// Using Binary Search
// Time Complexity: O(log X) - Binary search over the range [1, X]
// Space Complexity: O(1) - Constant auxiliary space used

class Solution2 {
public:
    int mySqrt(int x) {
      int low = 1 ;
      int high = x ;
      int ans = 0;
      while(low <= high)
      {
            int mid = low + (high - low) / 2 ;
            if (1LL * mid * mid <= x)
            {
                ans = mid ;
                low = mid + 1 ;
            }
            else
            {
                high = mid - 1 ;
            }
      } 
      return ans;
    }
};