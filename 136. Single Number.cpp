// Solution in CPP 
// Approach - 2 (Optimal Approach)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       // optimal solution 
       int ans = 0 ;
       for(int i= 0 ; i<nums.size();i++)
       {
        ans = ans ^nums[i];
       }
       return ans ;
    }
};


// Appraoch - 1 (brute force method)  


 int n = nums.size();
        map<int,int>m;
        for(int a: nums)
        {
            m[a]++;
        }
        int ans = nums[0] ;
        for(auto a : m)
        {
            if(a.second==1)
            {
                ans = a.first ;
            }
        }
        return ans ;

