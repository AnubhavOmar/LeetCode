// Solution of LeetCode Problem 
// 485. Max Consecutive Ones

// Approach  

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 ,maxcount= -1 ;
        int n  = nums.size(); 
        for(int i = 0 ; i< n ;i++)
        {
            if (nums[i] == 1 )
            {
                count ++;

            }
            else
            {
                maxcount = max(count , maxcount); 
                count  = 0 ;
            } 
        }
        return  max(maxcount,count);
    }
};