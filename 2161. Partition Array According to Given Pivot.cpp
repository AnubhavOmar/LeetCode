// Solution of LeetCode POTD
// 2161. Partition Array According to Given Pivot
// Solution in CPP

// Approach - 2 (Making ans vector and then inserting first all small elements form the pivot element and then inserting all the equal elements with pivot element and then all greater element from the pivot element )

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans ;
        for(int i = 0 ; i < nums.size() ; i++) 
        {
            if(nums[i] < pivot)
            {
                ans.push_back(nums[i]);
            }
        } 

        for(int i = 0 ; i < nums.size() ; i++) 
        {
            if(nums[i] == pivot)
            {
                ans.push_back(nums[i]);
            }
        }

        for(int i = 0 ; i < nums.size() ; i++) 
        {
            if(nums[i] > pivot)
            {
                ans.push_back(nums[i]);
            }
        } 
        return ans; 
    }
};


// Approach - 1 (Extracting all elements from the nums and then inserting them )

class Solution1 {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>greater;
        vector<int>equal;
        vector<int>smaller;

        for(int i = 0 ; i < nums.size() ; i++) 
        {
            if(nums[i] > pivot)
            {
                greater.push_back(nums[i]);
            }
            else if(nums[i] < pivot)
            {
                smaller.push_back(nums[i]);
            }
            else 
            {
                equal.push_back(nums[i]);
            }
        }

        nums.clear();

        for(int i = 0 ; i < smaller.size();i++)
        {
            nums.push_back(smaller[i]);
        }

        for(int i = 0 ; i < equal.size();i++)
        {
            nums.push_back(equal[i]);
        }

        for(int i = 0 ; i < greater.size();i++)
        {
            nums.push_back(greater[i]);
        }
        return nums;
    }
};
