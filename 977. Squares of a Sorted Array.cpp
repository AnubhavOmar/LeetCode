// Solution of Leetcode Problem 
// 977. Squares of a Sorted Array

// Appraoch 2 (optimal solution)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0 , j = nums.size()- 1 ; 
        vector <int> ans ;
        while(i<=j)
        {
            if(abs(nums[i]) < (nums[j]) )
            {
                ans.push_back(pow(nums[j], 2));
                j--;
            }
            else
            {
                ans.push_back(pow(nums[i], 2));
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};







// Approach 1 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());

        return move(nums);
    }
};