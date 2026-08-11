// Solution of LeetCode POTD
// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// Solution in CPP

// Approach - 1
// Using Hash Set and Prefix Sum
// Time Complexity: O(N) - Traversing the array to find the sequential prefix and populate/lookup in the unordered_set
// Space Complexity: O(N) - Storing elements of the array in an unordered_set

class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();
        int sum = nums[0];

        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] == nums[i] - 1)
            {
                sum += nums[i];
            }
            else
            {
                break;   // Stop when the sequential prefix ends.
            }
        }

        /* Check whether the current sum exists in the array.
           If it exists, increment the sum and check again.
           Return the first sum value that is not present in the array.
        */
        while (st.find(sum) != st.end())
        {
            sum++;
        }

        return sum;
    }
};

// Approach - 2
// Using Hash Map and Prefix Sum
// Time Complexity: O(N) - Traversing the array to populate the unordered_map and find the sequential prefix
// Space Complexity: O(N) - Storing elements and their indices in an unordered_map

class Solution1 {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int sum = nums[0];

        unordered_map<int,int> ump;

        for (int i = 0; i < n; i++)
        {
            ump[nums[i]] = i;
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] == nums[i] - 1)
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }

        // Find the first missing integer starting from sum.
        while (ump.find(sum) != ump.end())
        {
            sum++;
        }

        return sum;
    }
};

