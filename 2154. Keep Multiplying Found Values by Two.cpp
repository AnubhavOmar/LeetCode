// Solution of LeetCode Problem
// 2154. Keep Multiplying Found Values by Two

// Approach 1 (Using unordered map)


class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_map<int, int> m;
        for (int a : nums)
        {
            m[a]++;
        }
        int double_original = original;
        while (m.find(double_original) != m.end())
        {
            double_original *= 2;
        }

        return double_original;
    }
};

// Appraoch (Using Find function of vector )

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int double_original = original;
        while (find(nums.begin(),nums.end(),double_original) != nums.end()) {
            double_original *= 2;
        }

        return double_original;
    }
};
