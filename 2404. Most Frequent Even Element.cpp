// Solution of leetCode Problem 
// 2404. Most Frequent Even Element
// Solution in CPP


// Approach 1: Using a frequency map 
// Time Complexity: O(N log N) 
// Space Complexity: O(N) 

class Solution1 {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int > mp ;
        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            mp[nums[i]]++;
        }

        int ans = -1;
        int maxfreq = -1;

        for(auto a : mp)
        {
            if(a.first % 2 == 0 && maxfreq < a.second )
            {
                ans = a.first ;
                maxfreq = a.second;
            }
        }
        return ans;
    }
};

// Approach 2: Using an unordered_map with frequency and tie-breaking
// Time Complexity: O(N) 
// Space Complexity: O(N) 


class Solution2 {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums)
        {
            mp[num]++;
        }

        int ans = -1;
        int maxfreq = -1;

        for (auto a : mp)
        {
            if (a.first % 2 != 0)
                continue;

            if (a.second > maxfreq)
            {
                maxfreq = a.second;
                ans = a.first;
            }
            else if (a.second == maxfreq && (ans == -1 || a.first < ans))
            {
                ans = a.first;
            }
        }

        return ans;
    }
};