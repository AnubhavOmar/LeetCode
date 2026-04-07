// Solution of LeetCode Problem 
// 34. Find First and Last Position of Element in Sorted Array
// Solution in CPP 

// Approach - 1 (Using for loop)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target) return { 0 , 0 };

        
        vector<int> ans ;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(nums[i] == target)
            {
                ans.push_back(i);
            }
        }

        if(ans.size() == 0 ) return { -1 , -1 } ; 
        
        return { ans[0] , ans [ans.size() - 1] } ;
    }
};