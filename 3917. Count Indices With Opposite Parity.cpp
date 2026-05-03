// Solution of LeetCode Problem 
// 3917. Count Indices With Opposite Parity
//  Solution in CPP 

// Appraoch -  1 (Brute Force)
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int  n = nums.size() ;
        vector<int> ans(n);
        
        for(int i = 0 ; i < n ; i++ )
        {
            int count = 0 ;
            for(int j = i+1; j<n ; j= j+1)
            {
                if((nums[j] % 2) != (nums[i] % 2))
                {
                    count++;                    
                }
            }
            ans[i] = count ;
        }
        return ans;
    }
};


// Approach -2 (Time Complexity : O(n) )

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int  n = nums.size() ;
        vector<int> odd(n);
        vector<int> even(n);
        int count_even = 0; 
        int count_odd = 0; 
        // storing that where is even and odd in reverse direction because we need the updated data i.e we are counting in brute force in second loop 
        for(int i = n - 1; i >= 0; i--)        
        {
            odd[i] = count_odd;
            even[i] = count_even;

            if(nums[i] % 2 == 0 ) count_even++;
            else count_odd++ ;
        }

        vector<int> Ans(n);
        for(int i = 0 ; i < n; i++)
        {
            if(nums[i]%2 == 0) Ans[i] = odd[i];
            else Ans[i] = even[i];
        }
        return Ans;
    }
};