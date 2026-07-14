// Solution of LeetCode Problem 
// 2089. Find Target Indices After Sorting Array
// Solution in CPP 

// Approach - 2
class Solution2 {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans ;
        int low = 0 ;
        int high = nums.size() - 1 ;
        int idx = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                idx = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1 ;
            }
            else 
            {
                high = mid - 1;
            }
        }
        if(idx == -1) return {} ;
        for(int i = idx ; i < nums.size() && nums[i] == target   ; i++)
        {
            ans.push_back(i);
        }
        for(int i = idx-1 ; i >= 0  && nums[i] == target  ; i--)
        {
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Approach - 1
class Solution1 {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans ;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};