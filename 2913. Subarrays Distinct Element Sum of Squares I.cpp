// Solution of LeetCode Problem
// 2913. Subarrays Distinct Element Sum of Squares I
// Solution in CPP

// Approach - 1
// Using Brute Force Subarray Enumeration with an Unordered Set
// Time Complexity: O(n^3) average - There are O(n^2) subarrays, and constructing each subarray and set takes O(n) average time.
// Space Complexity: O(n) - The temporary subarray and unordered set can contain up to n elements.

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<vector<int>> all_subset ;
        int n = nums.size() ;
        
        int ans = 0 ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                vector<int>vec ;
                for(int k = i ; k <= j ; k++)
                {
                    vec.push_back(nums[k]);
                }
                unordered_set<int> st (vec.begin() , vec.end());
                int distinct_value = st.size() ;
                ans +=  distinct_value * distinct_value;
            }
        }

        return ans;

    }
};

// Approach - 2
// Using Brute Force Subarray Storage and Distinct-Element Counting
// Time Complexity: O(n^3) average - Storing all subarrays and processing their elements together takes O(n^3) average time.
// Space Complexity: O(n^3) - Storing all O(n^2) subarrays requires O(n^3) total elements.

class Solution1 {
public:
    int sumCounts(vector<int>& nums) {
        vector<vector<int>> all_subset ;
        int n = nums.size() ;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                vector<int>vec ;
                for(int k = i ; k <= j ; k++)
                {
                    vec.push_back(nums[k]);
                }
                all_subset.push_back(vec) ;
            }
        }

        // for(int i = 0 ; i < all_subset.size() ; i++)
        // {
        //     for(int j = 0 ; j < all_subset[i].size() ; j++)
        //     {
        //         cout << all_subset[i][j];
        //     }
        //     cout << "\n\n\n\n" ;
        // }

        int ans = 0 ; 
        for(int i = 0 ; i < all_subset.size() ; i++)
        {
            int val = unique_values(all_subset[i]) ;
            // cout<< val << endl; 
            ans +=  val * val ;
        }
        return ans;

    }
    int unique_values(vector<int> nums)
    {
        if(nums.size() == 1) return 1 ;
        unordered_set<int> st (nums.begin() , nums.end());
        return st.size() ;
    }
};