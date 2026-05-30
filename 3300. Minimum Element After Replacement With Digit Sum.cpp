// Solution of LeetCode POTD
// 3300. Minimum Element After Replacement With Digit Sum
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0 ; i<nums.size();i++)
        {
            int number = nums[i];
            nums[i]= 0 ;
            while(number != 0)
            {
                nums[i] = nums[i] + (number % 10) ;
                number /= 10 ;
            }
            ans = min(ans , nums[i]);
        }
        return ans;
    }
};