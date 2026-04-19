// Solution of LeetCode POTD 
// 1855. Maximum Distance Between a Pair of Values
// Solution in CPP 

// Approach - 3 ( Using modified binary search to find range of elements in nums2 which are >= nums1[i] and get the farthest valid index j )

class Solution {
public:
        int ans = INT_MIN ; // global variable which will be updated by the modified_search
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            modified_search(nums2 , nums1[i] , i);
        }

        return ans == INT_MIN ? 0 : ans  ;
    }
private : 
    void modified_search(vector<int> & nums2 , int target , int start_index)
    {
            int i = start_index;
            int j = nums2.size()- 1;
            while(i<=j)
            {
                int mid = i + (j-i) / 2 ;
                if(nums2[mid] >= target)
                {
                    ans = max(ans , mid - start_index);
                    i = mid + 1 ; // iski wajah se right side search kar rhe hai nums2 me 
                }
                else
                {
                    j = mid - 1 ;
                }
            }
    }
};


// Approach - 2 
class Solution2 {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN ;
        int i = 0 ; 
        
        for(int i = 0 ; i <nums1.size() ; i++)
        {
            int j = i ; 
            while(j<nums2.size() && nums1[i] <= nums2[j])
            {
                ans = max(ans , j - i);
                j++;
            }
        }
        return ans == INT_MIN ? 0 : ans  ;
    }
};




// Approach - 1 (Brute Force Approach) 
class Solution1 {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN ;
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            for(int j = i ; j < nums2.size() ; j++)
            {
                if(i<=j && nums1[i]<=nums2[j])
                {
                    ans = max(ans , j - i);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans  ;
    }
};

