// Solution of LeetCode Problem 
// 1877. Minimize Maximum Pair Sum in Array
// Solution in CPP 

// Approach - 1 (Two Pointers Approach)

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end());

    int l = 0, r = n-1;
    int maxx = INT_MIN ;
    while(l < r) 
    {
        maxx = max(maxx , nums[l]+nums[r]);
        l++;
        r-- ;
    }
    return maxx ;
    }
};
