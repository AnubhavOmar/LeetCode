// Solution of LeetCode Problem 
// 137. Single Number II 
// Solution in cpp 

// Appraoch - 2 (using sort function)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
     sort(nums.begin(),nums.end());
    int ans =nums[0] ;
        for(int i = 1 ; i<nums.size() -1 ;i++)
        {
            if(nums[i] != nums[i-1] && nums[i]!=nums[i+1]) ans =  nums[i];
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        return ans ;
    }
};




// Appraoch - 1 (Using maps)

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> m ;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            m[nums[i]]++ ;
        }
        for(auto  a : m)
        {
            if(a.second == 1)
            return a.first ;
        }
        return -1 ;


    }
};