// Solution of LeetCode Problem
// 1. Two Sum
// Solution in C++

// ==========================================================
// Approach - 5 (Sorting + Two Pointers)
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
// ==========================================================
// Store each element along with its original index.
// Sort the array based on element values.
// Use two pointers to find the required pair.
// Return the original indices stored in the pair.

class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<pair<int, int>> arr;

        // Store value along with its original index
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        int i = 0;
        int j = n - 1;

        while (i < j) {

            int sum = arr[i].first + arr[j].first;

            if (sum == target) {
                return {arr[i].second, arr[j].second};
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {};
    }
};


// ==========================================================
// Approach - 4 (Sorting + Binary Search)
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
// ==========================================================
// Store each element along with its original index.
// Sort the array.
// For every element, binary search its complement
// in the remaining sorted array.

class Solution5 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<pair<int, int>> arr;

        // Store value along with its original index
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {

            int required = target - arr[i].first;

            int low = i + 1;
            int high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (arr[mid].first == required) {
                    return {arr[i].second, arr[mid].second};
                }
                else if (arr[mid].first < required) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return {};
    }
};

// ==========================================================
// Approach - 3 (Optimal - Single Pass HashMap)
// Time Complexity  : O(n)
// Space Complexity : O(n)
// ==========================================================
// We find the required complement and insert elements into the
// unordered_map in a single traversal.
// If the complement already exists in the map, we have found
// the required pair. Otherwise, store the current element and
// its index in the map.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (um.find(complement) != um.end()) {
                return {um[complement], i};
            }

            um[nums[i]] = i;
        }

        return {};
    }
};


// ==========================================================
// Approach - 2 (Two Pass HashMap)
// Time Complexity  : O(2n) ≈ O(n)
// Space Complexity : O(n)
// ==========================================================
// First pass: Store every element and its index in the map.
// Second pass: Search for the complement of each element.
// Ensure that we do not use the same index twice.

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> um;

        // Store element and its index
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }

        // Search for the complement
        for (int i = 0; i < nums.size(); i++) {

            auto it = um.find(target - nums[i]);

            if (it != um.end() && it->second != i) {
                return {i, it->second};
            }
        }

        return {};
    }
};


// ==========================================================
// Approach - 1 (Brute Force)
// Time Complexity  : O(n²)
// Space Complexity : O(1)
// ==========================================================
// Check every possible pair of elements.

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};