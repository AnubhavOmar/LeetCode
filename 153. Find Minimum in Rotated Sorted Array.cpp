// Solution of LeetCode Problem 
// 153. Find Minimum in Rotated Sorted Array
// Solution in CPP 

// Appraoch - 1  using (for loop)
// Time Complexity : O(n) 

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1 ) return nums[0];
        for(int i = 0 ;i<nums.size()-1 ;i++)
        {
            if(nums[i] > nums[i+1])
            {
                return nums[i+1];
            }
        }
        return nums[0];
    }
};


// Appraoch - 2  (Using Sort Function )
// Time complexity : O(nlogn)

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        return nums[0];
    }
};


// Appraoch - 3  (Using Binary Search )
// Time complexity : O(logn)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1 ;
        int ans = INT_MAX ;
        while(low <= high)
        {
            if (nums[low] <= nums[high])
            {
                // if the whole array is sorted or we cross the point of rotation of the array 
                ans = min(ans, nums[low]);
                break;
            }
            int mid = low + (high - low) / 2 ;
            if(nums[low] <= nums[mid])   // Left half is sorted
            {
                // first find left is sorted then storing the low ptr value because it will pointing to the smallest element on that sorted part 
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else                         // Right half is sorted
            {
                // here right part is sorted then storing the mid ptr value because it will pointing to the smallest element on the right sorted part 
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }        
        return ans;
    }
};