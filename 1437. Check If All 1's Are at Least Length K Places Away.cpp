// Solution of LeetCode problem 
// 1437. Check If All 1's Are at Least Length K Places Away 

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       int first_i ;
       for(int i =0 ; i<nums.size() ;i++)
       {
        if (nums[i]==1) 
        {
            first_i = i ;
        break ; }
       }
       for(int i = first_i+1 ;i <nums.size() ;i++)
       {
        if(nums[i] == 1 &&  ((i-first_i-1)<k) ) return false;
        else if (nums[i]==1) first_i = i ;
       }
       return true; 


    }
};