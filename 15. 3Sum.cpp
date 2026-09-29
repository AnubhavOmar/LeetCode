// Solution of LeetCode Problem 
// 15. 3Sum
// Solution in CPP

// Approach - 1
// Using Sorting and Two Pointers
// Time Complexity: O(n^2) - Sorting takes O(n log n), followed by an O(n^2) scan.
// Space Complexity: O(log n) - The in-place sort uses O(log n) stack space; output is excluded.
// Explanation: We first sort the array. Then we iterate through each element `i`. For each `i`, we use two pointers `j` (starting at `i+1`) and `k` (starting at `n-1`) to find if `nums[i] + nums[j] + nums[k] == 0`. We increment `j` if sum is less than 0, decrement `k` if sum is greater than 0, and record the triplet if sum is 0. To avoid duplicates, we skip identical consecutive elements for `i`, `j`, and `k`.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end());

        vector<vector<int>>ans ;

        for(int i = 0 ; i < n ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int j = i + 1 ;
            int k = n - 1 ;

            while(j < k )
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                {
                    j++ ;
                }
                else if(sum > 0)
                {
                    k--; 
                }
                else 
                {
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                    while( j < k && nums[j] == nums[j-1]) j++;
                    while( j < k && nums[k] == nums[k+1]) k--;
                }
            }

        }
        return ans;
    }
};

// Approach - 2
// Using a Hash Map for value indices and a Set for unique triplets
// Time Complexity: O(n^3 log n) expected - Matching-index scans can total O(n^3); set insertions take O(log n).
// Space Complexity: O(n^2) - The set can store O(n^2) unique triplets; the hash map stores O(n) indices.

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> temp_set;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int target = -(nums[i] + nums[j]);

                if (mp.find(target) != mp.end())
                {

                    for (int idx : mp[target])
                    {

                        if (idx != i && idx != j)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[idx]};
                            sort(temp.begin(), temp.end());
                            temp_set.insert(temp);

                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(temp_set.begin() , temp_set.end() );

        return ans;
    }
};

// Approach - 3
// Using Brute Force with Three Nested Loops and a Set
// Time Complexity: O(n^3 log n) - The loops generate O(n^3) candidates, with set insertion costing O(log n).
// Space Complexity: O(n^2) - The set can store O(n^2) unique triplets; output space is excluded.

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> anss;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};

                        sort(temp.begin(), temp.end());

                        anss.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(auto x : anss)
        {
            ans.push_back(x);
        }

        return ans;
    }
};