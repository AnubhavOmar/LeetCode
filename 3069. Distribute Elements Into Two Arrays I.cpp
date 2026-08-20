// Solution of LeetCode Problem
// 3069. Distribute Elements Into Two Arrays I
// Solution in CPP

// Approach - 1
// Simulation using two vectors
// Time Complexity: O(N) - Traversing the nums array of size N once
// Space Complexity: O(N) - Extra space for storing elements in vec1, vec2, and ans vectors
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> vec1 ;
        vector<int> vec2 ;
        int n = nums.size() ;

        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);

        int last_ele_arr1 = vec1[0] ;
        int last_ele_arr2 = vec2[0] ;

        for(int i = 2 ; i < n ; i++)
        {
            if(last_ele_arr1 > last_ele_arr2)
            {
                last_ele_arr1 = nums[i] ;
                vec1.push_back(nums[i]) ;
            }
            else
            {
                last_ele_arr2 = nums[i] ;
                vec2.push_back(nums[i]) ;
            }
        }
        
        vector<int> ans ;
        
        for(int i = 0 ; i < vec1.size() ; i++ )
        {
            ans.push_back(vec1[i]) ;
        }
        
        for(int i = 0 ; i < vec2.size() ; i++ )
        {
            ans.push_back(vec2[i]) ;
        }
        return ans;
    }
};