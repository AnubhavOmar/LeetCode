// Solution of LeetCode Problem 
// 189. Rotate Array 
// Solution in CPP 

// Appraoch - 1  Space Complexity =  O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size()  ; 
        k = k % n;
        for(int i = n-k; i<n; i++)
        {
            ans.push_back(nums[i]);
        }
        for(int i = 0 ; i < n - k  ; i++)
        {
            ans.push_back(nums[i]);
        }
        nums.clear() ;
        
        for(int i = 0 ; i<n ;i++)
        {
            nums.push_back(ans[i]);
        }
    }
};


