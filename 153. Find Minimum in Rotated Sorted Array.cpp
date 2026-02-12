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
