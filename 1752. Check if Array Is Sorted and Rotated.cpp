// Solution of LeetCode POTD
// 1752. Check if Array Is Sorted and Rotated
// Solution in CPP 

// Approach - 2 (Using Recurssion)

class Solution {
public:

    bool solve(vector<int>& nums, int i, int breaks) {
        int n = nums.size();

        if(i == n) {
            return breaks <= 1;
        }

        // count breaks
        if(nums[i] > nums[(i + 1) % n]) {
            breaks++;
        }

        return solve(nums, i + 1, breaks);
    }

    bool check(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};

// Approach - 1 (Using Normal Iteration)

class Solution1 {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() ;
        int breaks = 0 ; 
        for(int i = 0 ; i<n ;i++)
        {
            if(nums[i] >nums[(i+1)%n])
            {
                breaks++;
            }
        }
        return breaks <= 1 ;
    }
};