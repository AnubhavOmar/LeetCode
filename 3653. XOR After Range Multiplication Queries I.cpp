// Solution of LeetCode POTD 
// 3653. XOR After Range Multiplication Queries I
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        const int MOD = 1e9 + 7 ; 


        for(int i = 0 ; i<queries.size() ; i++)
        {
            int idx = queries[i][0];
            
            while( idx <= queries[i][1] )
            {
                nums[idx] = ( 1LL * nums[idx] * queries[i][3] ) % MOD ;

                idx += queries[i][2];
            }
        }

        int ans = 0 ;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            ans ^= nums[i];
        }
        return ans; 
    }
};