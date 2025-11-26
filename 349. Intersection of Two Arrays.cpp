// Solution of LeetCode Problem 
// 349. Intersection of Two Arrays 

// Approach - 2 (Using Unordered map and then finding and pushing the values from the  map )
#include<vector>
#include<algorithm>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ; 
        vector<int> ans; 
        unordered_map<int,int> m1 ;
        unordered_map<int,int> m2 ;
        for(auto a : nums1 )
        {
            m1[a]++ ;
        }
        for(auto a : nums2 )
        {
            m2[a]++ ;
        }
        int ms1 = m1.size();
        int ms2 = m2.size();
        if (ms1 < ms2 ){
            for(auto a : m2) 
            {
                if(m1.find((a.first)) != m1.end()) ans.push_back(a.first);
            }
        }
        else {
            for(auto a : m1) 
            {
                if(m2.find((a.first)) != m2.end()) ans.push_back(a.first);
            }
        }
        
        return ans;

    }
};


// Appraoch - 1   (Using sets and Intersection Function )
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> temp;

        set_intersection(nums1.begin(), nums1.end(),
                         nums2.begin(), nums2.end(),
                         back_inserter(temp));

        unordered_set<int> inter(temp.begin(), temp.end());

        vector<int> ans(inter.begin(), inter.end());
        return ans;
    }
};
