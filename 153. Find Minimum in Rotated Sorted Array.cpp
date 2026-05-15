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
        int i = 0 ; 
        int j = nums.size() - 1;
        while(i<j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] < nums[j])
            {
                j = mid ;
            }
            else if (nums[mid] > nums[j])
            {
                i = mid + 1;
            }
        }  
        return nums[i];
    }
};