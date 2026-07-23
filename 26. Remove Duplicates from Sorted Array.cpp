// Solution of LeetCode problem 
// 26. Remove Duplicates from Sorted Array
// Solution in CPP 

// Appraoch -1 
//brute force 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      set<int> s ;
      for(auto a: nums) {
        s.insert(a);
      }
      nums.clear() ;
      for(auto a : s)
      {
        nums.push_back(a);
      }
      return s.size() ;
    }
};

// Appraoch - 2 
// USING MAPS
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        for(int a:nums)
        {
            m[a]++;
        }
        nums.clear();
        for(auto a:m){
            nums.push_back(a.first);
        }
        return m.size();
    }
};
// Approach - 3 (Brute Force)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};


// Approach - 4 (Two Pointers with Previous Variable)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int previous = nums[i];
        int j = 1;

        while (i < n && j < n) {
            if (previous == nums[j]) {
                j++;
            } else {
                i++;
                previous = nums[j];
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return i + 1;
    }
};


// Approach - 5 (Optimal Two Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        while (j < n) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
};