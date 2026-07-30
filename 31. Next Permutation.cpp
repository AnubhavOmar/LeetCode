// Solution of LeetCode Problem 
// 31. Next Permutation
// Solution in CPP


// Approach 1: Brute Force (Generate all permutations)
// Time Complexity: O(N! * log(N!) * N)
// Space Complexity: O(N! * N)


class Solution1 {
public:
    void nextPermutation(vector<int>& nums)
    {
        vector<vector<int>> all_permutation = permute(nums);

        sort(all_permutation.begin(), all_permutation.end());

        int idx = -1;

        for (int i = 0; i < all_permutation.size(); i++)
        {
            if (all_permutation[i] == nums)
            {
                idx = i;
                break;
            }
        }

        if (idx == all_permutation.size() - 1)
            nums = all_permutation[0];
        else
            nums = all_permutation[idx + 1];
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> all_permutations;
        vector<int> array;
        unordered_map<int, int> mp;

        genrate_all_permutations(nums, mp, all_permutations, array);

        return all_permutations;
    }

    void genrate_all_permutations(vector<int>& nums,
                                  unordered_map<int, int>& mp,
                                  vector<vector<int>>& all_permutations,
                                  vector<int>& array)
    {
        if (array.size() == nums.size())
        {
            all_permutations.push_back(array);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!mp[nums[i]])
            {
                mp[nums[i]] = 1;
                array.push_back(nums[i]);

                genrate_all_permutations(nums, mp, all_permutations, array);

                array.pop_back();
                mp[nums[i]] = 0;
            }
        }
    }
};


// Approach 2: Using STL next_permutation()
// Time Complexity: O(N)
// Space Complexity: O(1)


class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};


// Approach 3: Optimal
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};