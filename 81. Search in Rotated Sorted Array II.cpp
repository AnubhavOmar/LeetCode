// Solution of LeetCode Problem
// 81. Search in Rotated Sorted Array II
// Solution in C++

// Approach 1: Binary Search
// Time Complexity: O(log n) [Average Case], O(n) [Worst Case]
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            if(nums[mid] == target)
            {
                return true;
            }

            if(nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                // this part of code is for duplicates that if we found duplicates then we just need to shrink the pointers
                low++;
                high--;
                continue;
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
        return false;
    }
};

// Approach 2: Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution1 {
public:
    bool search(vector<int>& nums, int target) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == target)
            {
                return true;
            }
        }
        return false;
    }
};