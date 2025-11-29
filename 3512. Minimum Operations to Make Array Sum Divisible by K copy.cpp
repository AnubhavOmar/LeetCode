// Solution of LeetCode problem 
// 3512. Minimum Operations to Make Array Sum Divisible by K
// Solution in CPP 

// Appraoch   

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0 ; 
        for(int i= 0 ; i<nums.size() ;i++)
        {
            sum += nums[i];
        }
        return sum % k;
    }
};