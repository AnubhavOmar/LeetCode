// Solution of LeetCode problem 
// 1018. Binary Prefix Divisible By 5 

// Approach - 1 

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       int rem = 0 ;
       vector<bool>ans ;
       for(int i = 0 ; i<nums.size(); i++)
       {
        rem = (rem *2 + nums[i]) % 5 ;
        if (rem ==  0) ans.push_back(true) ;
        else ans.push_back(false) ;
       } 
       return ans ;
    }
};