// Solution in Cpp 
// Optimal Appraoch

// Dutuch National Flag algorithm 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        

        int low = 0 ; 
        int mid =0 ; 
        int high = nums.size()-1 ;
        while(mid<=high)
        {
            if(nums[mid]==0) 
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) mid++;
            else 
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        } 

    }
};


// Better approach 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0 ; 
        int count_1 = 0 ; 
        int count_2 = 0 ; 

        for(int a:nums)
        {
            if(a==0) count_0++;
            if(a==1) count_1++;
            if(a==2) count_2++;
        }
        nums.clear() ;
        for(int i =0;i<count_0;i++) nums.push_back(0); 
        for(int i =0;i<count_1;i++) nums.push_back(1); 
        for(int i =0;i<count_2;i++) nums.push_back(2); 
        
    }
};