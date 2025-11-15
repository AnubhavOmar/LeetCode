// Solution in CPP 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        if (n == 1 ) return nums[0];
        map<int , int > m; 
        for(int a : nums)
        {
            m[a]++;
        }
        int maxtime=n/2 ;
        int number=0 ;
        for(auto a: m)
        {
            if(maxtime<a.second)
            {
                maxtime = a.second ;
                number = a.first;
            }
            
        }
        return number; 
    }
};