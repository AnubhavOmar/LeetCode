// Sollution of LeetCode problem 
//560. Subarray Sum Equals K 

// Approach 1 (Brute Force)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int a = 0;
        for (int i = 0; i < nums.size(); i++) {

            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum = sum + nums[j];
                if (sum == k) {
                    a++;
                }
            }
        }
        return a;
    }
};

// Appraoch 2 (Optimal Solution)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
       unordered_map<int, int> m ;
       int sum = 0 ;
       int count = 0 ;
       m[0]=1 ;
       for(int num : nums)
       {
        sum += num ;
        if(m.find(sum-k)!=m.end())
        {
            count = count + m[sum-k];
        }
        m[sum]++ ;

       }

        return count ;
    }
};
