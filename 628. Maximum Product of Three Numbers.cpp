// Solution of LeetCode POTD
// 628. Maximum Product of Three Numbers
// Solution in CPP

// Approach - 1 (sorting and then only using two combinations)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ; 

        int multiply_neg = nums[0] * nums[1] * nums[n-1] ;

        int multipy_pos = nums[n-3] * nums[n-2] * nums[n-1] ;
        
        return max(multiply_neg ,  multipy_pos) ;
    }
};

// Only Valid For Positive Present Nums 

class Solution1 {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size(); 

        int first_max = INT_MIN ;
        int first_max_idx = -1;
        for(int i = 0 ; i < n ; i++)
        {
            if(first_max < nums[i])
            {
                first_max = nums[i] ;
                first_max_idx = i ;
            }
        }

        int second_max = INT_MIN ;

        int second_max_idx = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] > second_max  && first_max_idx != i )
            {
                second_max = nums[i] ;
                second_max_idx = i ; 
            }
        }

        int third_max = INT_MIN ;
        int third_max_idx = -1 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(third_max < nums[i] && second_max_idx != i && first_max_idx != i )
            {
                third_max = nums[i] ;
                third_max_idx = i ;
            }
        } 

        return first_max * second_max * third_max ;

    }
};
