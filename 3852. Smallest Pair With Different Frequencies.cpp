// Solution of LeetCode Problem
// 3852. Smallest Pair With Different Frequencies
// Solution in CPP

// Approach - 1
// Using Frequency Array and Linear Search
// Time Complexity: O(N) - Traversing the array to compute frequencies and finding the smallest and second smallest valid elements
// Space Complexity: O(1) - Using a fixed-size frequency array of size 102
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        int n = nums.size();
        vector<int> freq(102, 0);

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        int smallest_element = INT_MAX;
        int second_small = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            smallest_element = min(smallest_element, nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > smallest_element && freq[nums[i]] != freq[smallest_element])
            {

                second_small = min(second_small, nums[i]);
            }
        }

        if (second_small == INT_MAX)
        {
            return {-1, -1};
        }

        return {smallest_element, second_small};
    }
};

// Approach - 2
// Using Frequency Array and Brute Force Nested Loops
// Time Complexity: O(N^2) - Checking all pairs in the array of size N using nested loops
// Space Complexity: O(1) - Using a fixed-size frequency array of size 102
class Solution2 {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int>ans (2,INT_MAX);
       
       
        int n = nums.size() ;
        vector<int> freq(102,0);
        for(int i = 0 ; i < n ; i++)
        {   
            freq[nums[i]]++;
        } 

        bool noPair = false;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j && nums[i] < nums[j] && freq[nums[i]] != freq[nums[j]])
                {
                    ans = min(ans , { nums[i] , nums[j]} );
                    noPair = true ;
                }
            }
        }
        return ( noPair ? ans : vector<int> { -1 , -1 } );
    }
};

// Approach - 3
// Using Hash Map and Brute Force Nested Loops
// Time Complexity: O(N^2) - Checking all pairs in the array of size N using nested loops with hash map frequency lookups
// Space Complexity: O(N) - Storing element frequencies in an unordered_map
class Solution1 {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int>ans (2,INT_MAX);
       
       
        int n = nums.size() ;
        unordered_map<int,int>ump;

        for(int i = 0 ; i < n ; i++)
        {   
            ump[nums[i]]++;
        } 

        bool noPair = false;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j && nums[i] < nums[j] && ump[nums[i]] != ump[nums[j]])
                {
                    ans = min(ans , { nums[i] , nums[j]} );
                    noPair = true ;
                }
            }
        }
        return ( noPair ? ans : vector<int> { -1 , -1 } );
    }
};