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

// Approach - 2 (Using Two Pointers)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() + nums2.size();
        int n = m / 2;

        int i = 0;
        int j = 0;

        int prev = 0;
        int curr = 0;

        for (int count = 0; count <= n; count++) {
            prev = curr;

            // if nums1 traversal is completed quilckly  
            if (i >= nums1.size()) {
                curr = nums2[j];
                j++;
            }

            // if nums2 traversal is completed quilckly 
            else if (j >= nums2.size()) {
                curr = nums1[i];
                i++;
            }

            else if (nums1[i] <= nums2[j]) {
                curr = nums1[i];
                i++;
            }

            else {
                curr = nums2[j];
                j++;
            }
        }

        if (m % 2 == 0) {
            return (prev + curr) / 2.0;
        }

        return curr;
    }
};