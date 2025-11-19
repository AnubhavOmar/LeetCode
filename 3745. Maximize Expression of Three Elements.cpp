// Solution  of LeetCode Problem 
// 3745. Maximize Expression of Three Elements

// Approach - 1 

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        
        int largest = -101; 
        int largest_index = -1 ;
        for(int i = 0 ; i <nums.size() ;i++)
        {
            if(largest<nums[i])
            {
                largest = nums[i]; 
                largest_index = i ;
            }
        }
        int smallest = 101 ; 
        int smallest_index = -1 ;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(largest_index != i && smallest>=nums[i] )
            {
                smallest = nums[i];
                smallest_index = i ;
            }
        }
        int second_largest = -101; 
        for(int i = 0 ; i<nums.size();i++)
        {
            if(largest_index != i && smallest_index != i && second_largest<=nums[i])
            {
                second_largest = nums[i];
            }
        }
         return ((largest+second_largest)-smallest);
    }
};