// Solution of LeetCode POTD
// 1833. Maximum Ice Cream Bars
// Solution in CPP

// Approach - 1 

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0 ; 
        sort(costs.begin(),costs.end());
        for(int i = 0 ; i<costs.size();i++)
        {
            if(coins >= costs[i])
            {
                coins -= costs[i];
                ans++;
            }
        }
        return ans;
    }
};