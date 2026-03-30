// Solution of LeetCode Problem 
// 219. Contains Duplicate II
// Solution in CPP 

// Approach - 1 

//  Time Complexity:: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp ; 
        for(int i = 0 ; i<nums.size() ; i++)
        {
            mp[nums[i]].push_back(i) ; 
        }

        for(auto a : mp )
        {
            vector<int>vec = a.second ; 
            for(int i = 0 ; i<vec.size() ; i++)
            {
                for(int j = i + 1 ; j<vec.size() ; j++)
                {
                    if(abs(vec[i]-vec[j]) <= k)
                    {
                        return true ;
                    }
                }
            }
        }
        return false ;


    }

};

// Approach - 2  (Used Single loop and map check and removing the indexes )

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {

            if (mp.find(nums[i]) != mp.end()) {

                for (int idx : mp[nums[i]]) {
                    if (abs(i - idx) <= k) {
                        return true;
                    }
                }

                vector<int> temp;
                for (int idx : mp[nums[i]]) {
                    if (i - idx <= k) {
                        temp.push_back(idx);
                    }
                }
                mp[nums[i]] = temp;
            }

            mp[nums[i]].push_back(i);
        }

        return false;
    }
};