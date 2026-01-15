// Solution of LeetCode Problem 
// 2595. Number of Even and Odd Bits
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    vector<int> evenOddBit(int n) {
        string bits = "";
        while( n!=0)
        {
            bits += to_string(n%2);
            n /= 2 ;
        }
        vector<int> ans = {0,0};
        for(int i = 0 ;i<bits.size();i++)
        {
            if(bits[i] == '1')
            {
                if( i % 2 == 0 )
                {
                    ans[0]++;
                }
                else 
                {
                    ans[1]++;
                }
            }
        }
        return ans ;


    }
};

