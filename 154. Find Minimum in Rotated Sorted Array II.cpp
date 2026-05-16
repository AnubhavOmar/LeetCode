// Solution of of LeetCode POTD 
// 154. Find Minimum in Rotated Sorted Array II
// Solution in CPP 

// Approach -1
// Time Complexity : O(log n)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0 ;
        int j = nums.size() - 1 ;
        while(i<=j)
        {
            int mid = (i + j) / 2 ;
            // first we find that which side contains minimum element 
            // if duplicates mid and j are duplicates so we shrink safely 
            if(nums[mid] > nums[j])
            {
                i = mid + 1 ;
            }
            else if(nums[mid] < nums[j])
            {
                j = mid;
            }
            else 
            {
                j--;
            }
        }
        return nums[i];
    }
};

// Approach - 2
// Time Complexity : O(n)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            minn = min(minn,nums[i]);
        }
        return minn;
    }
};
