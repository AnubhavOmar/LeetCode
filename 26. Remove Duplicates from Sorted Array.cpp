// Solution of LeetCode problem 
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

// Appraoch 3 
// Wihtout extra space 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size() ;
       if(n==0) return 0 ;
       int i = 0 ; 
       for(int j = 1 ;j<n ;j++)
       {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i]=nums[j];
            
        }
       }
        return i+1 ;


    }
};