// Solution of LeetCode Problem
// 162. Find Peak Element
// Solution in CPP

// Approach - 1
// Using Binary Search
// Time Complexity: O(log N) - Logarithmic search space reduction in the array of size N
// Space Complexity: O(1) - Constant auxiliary space used
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ;
        
        if (n == 1) return 0 ;

        if (nums[0] > nums[1]) return 0;
        
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1 ; 
        int high = n - 2 ;

        while(low <= high)
        {
            int mid = low + (high - low ) / 2 ;
            if(nums[mid] > nums[mid-1]  && nums[mid] > nums[mid+1] )
            {
                return mid ;
            }
            else if(nums[mid]  > nums[mid - 1])
            {
                low = mid + 1  ;
            }
            else 
            {
                high = mid - 1;
            }
        }
        return -1; 
    }
};

// Approach - 2
// Using Linear Search
// Time Complexity: O(N) - Traversing each element in the array of size N
// Space Complexity: O(1) - Constant auxiliary space used
class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ;

        if (n == 1) return 0 ;

        if (nums[0] > nums[1]) return 0;
        
        if (nums[n - 1] > nums[n - 2]) return n - 1;


        for(int i = 1;  i < n - 1 ; i++ )
        {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
            {
                return i;
            }
        }
        return -1 ;
    }
};