// Solution of LeetCode POTD
// 33. Search in Rotated Sorted Array
// Solution in CPP 

// Approach - 2 (Using Binary Search)
/*
Algorithm:
1. Initialize two pointers: low = 0, high = n - 1.
2. Loop while low <= high:
   a. Calculate mid = low + (high - low) / 2.
   b. If nums[mid] is target, return mid.
   c. Check if the right half is sorted (nums[mid] <= nums[high]):
      - If target lies within the sorted right half (nums[mid] <= target <= nums[high]), search right: low = mid + 1.
      - Else, search left: high = mid - 1.
   d. Otherwise, the left half is sorted:
      - If target lies within the sorted left half (nums[low] <= target <= nums[mid]), search left: high = mid - 1.
      - Else, search right: low = mid + 1.
3. If not found, return -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] <= nums[high])
            {
                // right part sorted 
                if(nums[mid] <= target && target <= nums[high])
                {
                    // means number exist in the right side then move pointer low to mid
                    low = mid + 1 ;
                }
                else
                {
                    // target  doesnot exist in the right side sorted part so move high pointer to mid 
                    high = mid - 1 ;
                }
            }
            else // nums[mid] >= nums[low]
            {
                // left part already sorted
                if(nums[mid] >= target && target >= nums[low])
                {
                    // so target exist in left side 
                    high = mid - 1;
                }
                else 
                {
                    low = mid + 1 ;
                }
            }
        }
            return -1;
    }
};

// Approach - 1 (Linear Search)

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] == target)
            {
                return i ;
            }
        }
        return -1;
    }
};