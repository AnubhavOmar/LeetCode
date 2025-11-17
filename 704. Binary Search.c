/ /// Sollution of LeetCode problem 
// 704. Binary Search In both c and cpp 


// Solution in C language 

int search(int* nums, int numsSize, int target) {
    int i = 0 ; 
    int j = numsSize -1 ;
    while(i<=j)
    {
        int mid = i + (j-i) /2 ; 
        if(nums[mid]==target) return mid ; 
        else if (nums[mid] > target ) j = mid - 1 ;
        else i = mid + 1 ;
    }
    return -1 ;
}

// Solution in cpp 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }
};