// Solution of LeetCode Problem 
// 4. Median of Two Sorted Arrays
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vecc ;
        for(int i = 0 ; i<nums1.size(); i++)
        {
            vecc.push_back(nums1[i]);
        }

        for(int i = 0 ; i<nums2.size() ; i++)
        {
            vecc.push_back(nums2[i]);
        }

        sort(vecc.begin() , vecc.end());
        
        int n = vecc.size() ;

        if(n%2 == 0)
        {
            double ans = ( (vecc[n/2] + vecc[(n/2)-1]) / 2.0);
            return ans ;
        }
        
        return vecc[n/2];
    }
};