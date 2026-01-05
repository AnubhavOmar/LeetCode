// Sollution of LeetCode problem 
// 3774. Absolute Difference Between Maximum and Minimum K Elements 


// Approach - 1 

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()) ;
        int largesum = 0 ; 
        for(int i = nums.size()-k;i<nums.size();i++)
        {
            largesum +=nums[i];
        }
        int smallsum = 0;
        for(int i = 0 ; i<k ;i++)
        {
            smallsum += nums[i] ;
        }
        return abs(largesum-smallsum);
    }
};