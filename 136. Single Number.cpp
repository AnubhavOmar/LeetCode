// Solution of LeetCode Problem 
// 136. Single Number
// Solution in CPP  

// Approach - 1 (Brute Force)
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int n =  nums.size();
        for(int i = 0 ; i < n ;i++)
        {
            bool found = false;
            for(int j = 0 ; j < n ;j++)
            {
                if( i != j && nums[i] == nums[j] )
                {
                    found = true; 
                    break; 
                }
            }
            if(!found)
            {
                return nums[i];
            }
        }
        return -1 ; // not reachable line ;
    }
};

// Approach - 2 (Sorting)
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size() ;
        for(int i = 1 ; i < n ; i+=2)
        {
            if(nums[i-1] != nums[i])
            {
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

// Approach - 3 (Hash Map / Frequency Count)
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
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
    }
};

// Approach - 4 (Bit Manipulation - XOR)
class Solution4 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

// Approach - 5 (Hash Set)
class Solution5 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> sett ;
        int n = nums.size() ;
        for(int i = 0 ;i<n;i++)
        {
            if(sett.find(nums[i]) != sett.end())
            {
                sett.erase(nums[i]);
            }
            else
            {
                sett.insert(nums[i]);
            }
        } 
        for(auto a : sett)
        {
            return a;
        }       
        return -1;
    }
};