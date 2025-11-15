// Sollution of LeetCode problem 
// 496. Next Greater Element 

//Optimal approach 


// brute force approach 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i<nums1.size() ;i++)
        {
            int idx = -1 ;
            for(int j = 0 ; j<nums2.size();j++)
            {
                if(nums2[j]==nums1[i]) idx = j ;
            }
            int flag =0 ;
            for(int j = idx ;j<nums2.size() ; j++)
            {
                if(nums1[i]<nums2[j]) 
                {
                    nums1[i]= nums2[j];
                    flag = 1 ; 
                    break ;   
                }
             
            }
            if (flag==0) nums1[i]=-1 ;

        }
        return nums1 ;

    }
};