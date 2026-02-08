// Solution of LeetCode Problem 
// 1. Two Sum 
// Solution in CPP 

// Appraoch -  3 

// Time Complexity = O(n) time reduced from O(2n) -> O(n)   
// Space Complexity = O(n) for map 
// we find the second number and inserting of elements in map using a single for loop if it does not exit then insert the element ,
//  if it exits means we find the second number by adding it with first number we will get to the target 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (um.find(complement) != um.end())
            {
                return { um[complement], i };
            }
            um[nums[i]] = i;
        }
        return {0, 0};
    }
};



// Appraoch - 2 Using Map 

// Time Complexity = O(2n)  
// Space Complexity = O(n) for map 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> um ; // using unordered map becuase searching time complexity is :  O(1)
        for(int i = 0 ; i<nums.size() ;i++)
        {
            um[nums[i]] = i  ; // this will store the element and its index in a map 
        }       
        for(int i = 0 ; i<nums.size();i++)
        {
            auto it = um.find(target - nums[i]);
            // this will find the second number , that will on adding with the first number gives the target  
            if(it != um.end() && it->second != i )
            {
                return { i  , it->second}; 
            }
        }
        return {0,0};
    }
};


// Approach - 1 
// Time Complexity = O(n^2)  
// Space Complexity = O(1) 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ;i<nums.size() ;i++){
            for(int j = i+1 ;j<nums.size() ;j++){
                if (nums[i]+nums[j] == target) return {i,j}; 
            }
        }
    return {0};
    }
};



