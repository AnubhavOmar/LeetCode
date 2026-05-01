// Solution of LeetCode POTD 
// 396. Rotate Function
// Solution in CPP 

// Approach - 2 (Using Previous Sum and then finding the new newF or new sum)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size() ;
        int maxx = INT_MIN;
        int total_sum = 0 ; 
        int sumF = 0 ;
        for(int i = 0 ; i <n ; i++)
        {
            sumF += (i * nums[i]); // calculation F(0)

            total_sum += nums[i];
        }
        maxx = sumF;
        for(int i = 1 ; i<n ;i++)
        {
            int new_sumF = sumF + total_sum - n * nums[n - i]; // Main Formula 
            maxx = max(new_sumF , maxx);
            sumF = new_sumF  ; // Updating Previous Sum 
        }
        return maxx ;
    }
};




// Approach - 1 :  Brute Force 

class Solution1 {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxx = INT_MIN;
        for(int i = 0 ; i<nums.size(); i++)
        {
            int sum = 0; 
            for(int j = 1 ; j <nums.size() ; j++)
            {
                sum = sum + (nums[j] * j );
            }
            rotate(nums);
            maxx = max(sum,maxx);
        }
        return maxx;
    }
    private : 
    void rotate(vector<int>& nums)
    {
        int temp = nums[nums.size()-1];
        for(int i = nums.size() - 1; i>0 ; i--)
        {
            nums[i] = nums[i-1] ;
        }
        nums[0] = temp ;
    }
};