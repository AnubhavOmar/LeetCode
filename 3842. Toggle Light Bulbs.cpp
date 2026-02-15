// Solution of LeetCode Problem 
// 3842. Toggle Light Bulbs
// Solution in CPP 

// Appraoch - 1 
// Using Map 

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans ;
        map<int,int> mp;
        for(auto a: bulbs)
        {
            mp[a]++;
        }
        for(auto a :mp)
        {
            if( (a.second % 2) == 1 )
            {
                ans.push_back(a.first);
            }
        }
        return ans ;
    }
};