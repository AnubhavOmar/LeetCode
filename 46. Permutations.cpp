// Solution of LeetCode Problem 
// 46. Permutations
// Solution in CPP

// Approach - 1  (Using Recursion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> all_permutations ;
         int n = nums.size() ;
         vector<int>array;
         unordered_map<int,int>mp(n);

         genrate_all_permutations(nums , mp , all_permutations , array);

         return all_permutations; 

    }

    void genrate_all_permutations(vector<int>& nums , unordered_map<int,int>& mp , vector<vector<int>>& all_permutations , vector<int>& array)
    {
        if(array.size() == nums.size())
        {
            all_permutations.push_back(array);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if( !(mp[nums[i]]) )
            {
                mp[nums[i]] = 1 ;

                array.push_back(nums[i]);

                genrate_all_permutations(nums , mp , all_permutations , array);

                array.pop_back() ;
                mp[nums[i]] = 0 ;

            }
        }

    }

};