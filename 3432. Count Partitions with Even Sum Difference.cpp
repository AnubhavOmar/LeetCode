// Solution of LeetCode problem 
// 3432. Count Partitions with Even Sum Difference
// Solution in CPP 

// Appraoch - 1 
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0 ; 
        int count = 0 ;
        for(int i = 0 ;i<nums.size(); i++)
        {
            sum += nums[i];
        }
        int left = 0 ;
        int right = sum ; 
        for(int i  = 0 ; i<nums.size()-1 ; i++)
        {
            left += nums[i];
            right = sum - left;
            if(abs(left-right)%2==0)
            {
                count++;
            }
        }
        
        return count ;
    }
};



// Appraoch - 2 (More Optimal)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int i = 0 ; i<nums.size(); i++)
        sum += nums[i];

        return (sum % 2) ? 0 : nums.size() - 1;
    }
};

