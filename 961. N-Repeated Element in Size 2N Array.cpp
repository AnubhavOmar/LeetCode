// Solution of LeetCode Problem 
// 961. N-Repeated Element in Size 2N Array
// Solution in CPP 

// Approach - 1  (Using maps) 

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (auto a : freq) {
            if (a.second == (int(nums.size() / 2))) {
                return a.first;
            }
        }
        return -1;
    }
};

// Appraoch - 2 ( Same as Appraoch - 1 but slightly less comparisions)

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>freq ;
        for(int i = 0 ; i<nums.size() ;i++)
        {
            freq[nums[i]]++;
        }

        for(auto a : freq)
        {
            if(a.second > 1)
            {
                return a.first;
            }
        }
        return -1;
    }
};

