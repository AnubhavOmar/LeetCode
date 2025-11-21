// Solution of LeetCode problem 
// 1929. Concatenation of Array 

// Approach - 2 without extra space 
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() ;
        for(int i = 0 ; i<n ;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums ;
    }
};

// Appraoch - 1  with extra space 
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans ;
        for(int a : nums)
        {
            ans.push_back(a);
        }
        for(int a : nums)
        {
            ans.push_back(a);
        }
        return ans ;
    }
};