// Solution in LeetCode Problem 
// 75. Sort Colors  
// Solution in Cpp 

// Approach 1: Three-Pass Swapping
// Time Complexity: O(3N) = O(N)
// Space Complexity: O(1)

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] != 0) {
                i++;
            } else {
                swap(nums[i++], nums[idx++]);
            }
        }

        i = 0;
        while (i < n) {
            if (nums[i] != 1) {
                i++;
            } else {
                swap(nums[i++], nums[idx++]);
            }
        }

        i = 0;
        while (i < n) {
            if (nums[i] != 2) {
                i++;
            } else {
                swap(nums[i++], nums[idx++]);
            }
        }
    }
};

// Approach 2: Counting Frequency + Rewrite Array
// Time Complexity: O(2N) = O(N)
// Space Complexity: O(1)

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count_0++;
            } else if (nums[i] == 1) {
                count_1++;
            } else {
                count_2++;
            }
        }

        for (int i = 0; i < count_0; i++) {
            nums[i] = 0;
        }

        for (int i = count_0; i < count_0 + count_1; i++) {
            nums[i] = 1;
        }

        for (int i = count_0 + count_1; i < count_0 + count_1 + count_2; i++) {
            nums[i] = 2;
        }
    }
};

// Approach 3: Counting Frequency + Single Reconstruction Loop
// Time Complexity: O(2N) = O(N)
// Space Complexity: O(1)

class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count_0++;
            } else if (nums[i] == 1) {
                count_1++;
            } else {
                count_2++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (count_0 != 0) {
                nums[i] = 0;
                count_0--;
            } else if (count_1 != 0) {
                nums[i] = 1;
                count_1--;
            } else if (count_2 != 0) {
                nums[i] = 2;
                count_2--;
            }
        }
    }
};