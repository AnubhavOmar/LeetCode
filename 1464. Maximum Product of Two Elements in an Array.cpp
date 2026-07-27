// Solution of LeetCode POTD
// 1464. Maximum Product of Two Elements in an Array
// Solution in CPP

// Approach - 1
// Time Complexity = O(N log(N) )
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()); 
        return (nums[n-1] - 1 ) * (nums[n-2] - 1) ;        
    }
};

// Approach - 2
// Time Complexity = O(N)
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;

        int first_max = INT_MIN;
        int second_max = INT_MIN;
        

        for(int i = 0 ; i < n ; i++)
        {
            if(first_max<nums[i])
            {
                second_max = first_max ;
                first_max = nums[i];
            }
            else if(second_max < nums[i] && first_max > second_max)
            {
                second_max = nums[i] ;
            }
        }
        return (first_max-1)*(second_max-1);
    }
};