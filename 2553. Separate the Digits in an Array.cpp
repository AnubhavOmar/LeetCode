// Solution of LeetCode POTD 
// 2553. Separate the Digits in an Array
// Solution in CPP 

// Approach - 2 

class Solution{
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            string s = to_string(nums[i]);

            for(int j = 0; j < s.size(); j++)
            {
                ans.push_back(s[j] - '0');
            }
        }

        return ans;
    }
};

// Approach - 1 

class Solution1 {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size() ;
        vector<string> number ;
        for(int i = 0 ; i<n ; i++)
        {
            number.push_back(to_string(nums[i]));
        }
        
        vector<int>ans; 
        for(int i = 0 ; i<number.size() ; i++)
        {
            int j = 0 ; 
            while(j<number[i].size())
            {
                ans.push_back( number[i][j] - '0' );
                j++;
            }
        }

        return ans;
    }  
};