// Solution of LeetCode Problem 
// 1356. Sort Integers by The Number of 1 Bits
// Solution in CPP 

// Appraoch - 1 
// (Using Map and Storing the bits which contains that same bit every number )

class Solution {
public:
// __builtin_popcount(number) 

    vector<int> sortByBits(vector<int>& arr) {
        
        map<int, vector<int>> mp; 
        
        for(int i = 0; i < arr.size(); i++)
        {
            int count = __builtin_popcount(arr[i]);
            mp[count].push_back(arr[i]);
        }
        for(auto &it : mp)
        {
        sort(it.second.begin(), it.second.end());
        }

        vector<int> result;
    
        for(auto &it : mp) {
            for(int num : it.second) {
                result.push_back(num);
            }
        }
        
        return result;

    }
};