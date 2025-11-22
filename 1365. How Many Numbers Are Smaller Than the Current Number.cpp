// Solution of LeetCode problem 
// 1365. How Many Numbers Are Smaller Than the Current Number 

// Appraoch - 1  (Brute Force)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans ; 
        for(int i = 0; i<nums.size() ;i++)
        {
            int count = 0 ; 
            for(int j = 0 ; j<nums.size();j++)
            {
                if(nums[i] >nums[j]) count++;
            }
            ans.push_back(count);
        }
        return ans; 

    }
};

